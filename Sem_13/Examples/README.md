# Design Patterns — Notes

A short reference on three classic Gang of Four (GoF) creational design patterns: **Singleton**, **Factory**, and **Prototype**.

A *design pattern* is a reusable, language-agnostic solution to a recurring design problem. Patterns are not algorithms — they are templates for how classes and objects collaborate to solve a particular kind of problem.

GoF patterns are divided into three families:

| Family       | Goal                                                | Examples                                  |
|--------------|-----------------------------------------------------|-------------------------------------------|
| Creational   | Control **how** objects are created                 | Singleton, Factory, Prototype, Builder    |
| Structural   | Compose classes/objects into larger structures      | Adapter, Decorator, Facade, Composite     |
| Behavioural  | Define how objects communicate / share responsibility | Observer, Strategy, Visitor, Iterator   |

The three patterns covered here are all **creational**.

---

## 1. Singleton

### Intent
Guarantee that a class has **exactly one instance** and provide a single, global point of access to it.

### Problem it solves
Some resources are logically unique in a program — the application's configuration, a logger, a printer spooler, the OS clipboard. Allowing arbitrary instances would introduce inconsistency (which config wins?) or waste resources (multiple connection pools).

### Structure
```
+---------------------+
|     Singleton       |
+---------------------+
| - instance: static  |
+---------------------+
| - Singleton()       |   <-- hidden constructor
| + getInstance() st. |   <-- single access point
+---------------------+
```

### Canonical C++ implementation (Meyers' Singleton)
```cpp
class Singleton
{
private:
    Singleton() = default;                          // hidden constructor

public:
    Singleton(const Singleton&) = delete;           // no copy
    Singleton& operator=(const Singleton&) = delete;// no assignment

    static Singleton& getInstance()
    {
        static Singleton instance;                  // created once, thread-safe (C++11+)
        return instance;
    }
};
```

### Key rules
- The constructor is **private** (or **protected** if you need a subclass).
- The copy constructor and copy assignment operator are **deleted** — otherwise the "one instance" guarantee is broken.
- `getInstance()` returns a **reference**, never a pointer or a value.
- The instance is created **lazily** — on the first call to `getInstance()`.
- A `static` local variable is initialized exactly once and destroyed automatically at program exit (since C++11 this is also thread-safe).

### When to use
- The class represents a logically unique resource (config, logger, cache).
- You want lazy initialization and controlled destruction.
- You need a global access point but want to avoid raw global variables.

### When NOT to use
- You only "have one for now" — that is not the same as "must always have one".
- The class would be easier to test by dependency injection.
- You are tempted to use it just as a globals namespace — use a plain namespace instead.

### Trade-offs
- Singletons hide dependencies (code can grab them from anywhere), which makes unit testing harder.
- They essentially become global state — overuse leads to tightly-coupled code.

---

## 2. Factory

### Intent
Encapsulate the **creation logic** of objects so that client code does not depend on the concrete classes being instantiated.

> The GoF distinguishes between the **Simple Factory** idiom, the **Factory Method** pattern, and the **Abstract Factory** pattern. The notes below describe the simplest and most common variant — the **Simple Factory** — which is what you'll usually meet first.

### Problem it solves
Without a factory, client code is forced to write something like:

```cpp
if (type == "free")  user = new FreeUser(...);
else if (type == "paid") user = new PaidUser(...);
else if (type == "pro")  user = new ProUser(...);
```

This `if/else` (or `switch`) tends to appear **everywhere** the hierarchy is used. Every time a new subclass is added, every such block must be updated — a clear violation of the **Open/Closed Principle**.

### Structure
```
+-------------+        +-------------------+
|   Client    | -----> |     Factory       |
+-------------+        +-------------------+
                       | + create(type)    |
                       +---------+---------+
                                 |
                                 v
                       +-------------------+
                       |   Product (abst.) |
                       +---------+---------+
                                 ^
                  +--------------+--------------+
                  |              |              |
              ProductA       ProductB        ProductC
```

### Canonical C++ implementation
```cpp
enum class ProductType { A, B, C };

class Factory
{
public:
    static Product* create(ProductType type)
    {
        switch (type)
        {
            case ProductType::A: return new ProductA();
            case ProductType::B: return new ProductB();
            case ProductType::C: return new ProductC();
        }
        throw std::invalid_argument("Unknown product type");
    }

    Factory() = delete;   // never instantiated
};
```

### Key rules
- Client code knows only about the **enum** (or some other type tag) and the **abstract base class** — never about the concrete subclasses.
- The factory is the **single place** where the mapping from tag to concrete class lives.
- The factory can carry **state** (counters, caches, registries) and apply **business rules** (discounts, quotas, throttling) during creation — this is one of its main strengths over a plain `new`.
- Ownership: the factory returns a raw `T*` (or, better in modern C++, a `std::unique_ptr<T>`). The caller takes ownership.

### When to use
- You instantiate objects from a polymorphic hierarchy in many places.
- Construction is non-trivial (lookups, counters, validation) and should be centralized.
- You expect new subtypes to be added over time — the factory becomes the single update point.

### Trade-offs
- Adding a new subtype still requires editing the factory (and possibly the enum). The **Factory Method** and **Abstract Factory** patterns trade simplicity for the ability to extend without modification.
- The factory becomes a dependency of every client that needs to create objects — which is usually fine, but worth noticing.

---

## 3. Prototype

### Intent
Create new objects by **cloning an existing instance** (the "prototype") instead of constructing them from scratch.

### Problem it solves
Suppose you have a `Base*` that points to some derived class. You want to make a deep copy, but you don't know — and don't want to know — the dynamic type:

```cpp
Base* original = /* could be DerivedA, DerivedB, or DerivedC */;
Base* copy     = new Base(*original);   // ❌ slices the object (and may not even compile if Base is abstract)
```

You cannot use the copy constructor of `Base` because it would slice off everything specific to the derived type. The **Prototype** pattern moves the "how to copy me" knowledge **into the object itself**.

### Structure
```
+--------------------------+
|       Prototype          |   <-- abstract base
+--------------------------+
| + clone() const = 0      |
+--------------------------+
              ^
              |
   +----------+----------+
   |                     |
ConcreteA            ConcreteB
+ clone() const      + clone() const
  { return new        { return new
    ConcreteA(*this);}  ConcreteB(*this);}
```

### Canonical C++ implementation
```cpp
class Shape
{
public:
    virtual Shape* clone() const = 0;
    virtual ~Shape() = default;
};

class Circle : public Shape
{
public:
    Shape* clone() const override { return new Circle(*this); }
};

class Square : public Shape
{
public:
    Shape* clone() const override { return new Square(*this); }
};
```

Then, polymorphic deep-copying is a one-liner regardless of the dynamic type:

```cpp
Shape* original = /* something */;
Shape* copy     = original->clone();   // ✅ correct concrete type
```

### Key rules
- `clone()` is **virtual** and overridden in every concrete subclass.
- Each override is typically a one-liner: `return new DerivedType(*this);` — it relies on the (compiler-generated or user-defined) copy constructor of the derived class.
- The base class **must** declare a `virtual` destructor, otherwise `delete` on the cloned pointer is undefined behaviour.
- The return type can use **covariant return types**: `Circle* Circle::clone() const override` is legal and sometimes useful.

### When to use
- You manage objects polymorphically (a container of `Base*`).
- You need to deep-copy those objects without coupling client code to the concrete subclasses.
- Object construction from scratch is expensive — cloning an existing, fully-initialized instance is cheaper.

### Trade-offs
- Every subclass must remember to implement `clone()` — easy to forget when extending the hierarchy.
- Deep copying of objects that reference each other (graphs, parent pointers) can become surprisingly tricky.

---

## How the three patterns combine in practice

These patterns are designed to **compose**:

- A **Factory** decides *which* concrete subtype to build.
- A **Prototype** then lets clients duplicate those polymorphic objects without re-asking the factory.
- A **Singleton** can sit at the very top, providing the unique global instance of the factory itself (so the registry of available subtypes is shared across the program).

A common layered design:

```
[ Singleton config / logger / id-generator ]
            ^
            |
[ Factory ]  -->  produces  -->  [ Product hierarchy with clone() ]
            ^
            |
[ Client code uses Base* — never touches concrete classes ]
```

---

## Further reading

- *Design Patterns: Elements of Reusable Object-Oriented Software* — Gamma, Helm, Johnson, Vlissides (the "Gang of Four" book).
- *Modern C++ Design* — Andrei Alexandrescu (singleton variants, policy-based design).
- *Effective C++* / *Effective Modern C++* — Scott Meyers (rationale behind the Meyers' singleton, virtual destructors, `= delete`).

## Task 1 — Singleton: Global Configuration Store

Design a class `Singleton` that represents a globally accessible configuration store. The class must guarantee that **at most one instance** of it can ever exist during the program's lifetime.

### Example usage
```cpp
Singleton& s = Singleton::getInstance();
s.setData("hello");
std::cout << Singleton::getInstance().getData(); // "hello"
```

## Task 2 — Class Hierarchy: Users with Subscriptions
Build the backend of a small subscription service. The service manages users of three different kinds, applies a pricing policy when new users join, and can report how much revenue it currently generates per month.

### 2.1 — Users

The service has three kinds of users:

| Kind | Monthly subscription price | Paid subscriber? |
|------|----------------------------|------------------|
| Free | always `0`                 | no               |
| Paid | base price `10`            | yes              |
| Pro  | base price `100`           | yes              |

Each user has:
- a **unique numeric id**, assigned automatically on creation (first user gets `0`, then `1`, `2`, …),
- a name and a password,
- a monthly subscription price,
- a way to tell whether they are a paying subscriber or not.

Free, Paid, and Pro users share the same general "user" concept but answer the "are you paying?" question differently and may carry different prices.

### 2.2 — Pricing policy (promotions)

When a new Paid or Pro user joins, the service may apply a promotional discount:

- Every **10th** Paid user that ever joins receives a **50% discount** on their monthly price (`5` instead of `10`).
- Every **100th** Pro user that ever joins receives a **50% discount** on their monthly price (`50` instead of `100`).
- Free users are always free.

This promotional logic must live **in one place** — adding a new user kind or changing a discount rule must not require touching the user types themselves or the server.

### 2.3 — The server

A `UserServer` holds up to `10000` users at the same time.

It must support:
- **Adding** a new user of a given kind. If the server is full, adding fails (throw an error). The pricing policy from 2.2 is applied during add.
- **Deleting** a user by id. The slot is freed and may later be reused by another `add`.
- **Querying** the total monthly revenue — the sum of the monthly prices of all users currently on the server.
- **Querying** how many users are currently on the server.

The server owns its users (it is responsible for destroying them). Copying or assigning one server to another must produce a **fully independent deep copy** — modifying or destroying one server must not affect the other, even though the users are stored polymorphically and the server does not know their concrete kinds.

```cpp
UserServer server;
server.addUser("Ivan",  "pass123", UserType::Free);  // id 0, price 0
server.addUser("Gosho", "pass123", UserType::Paid);  // id 1, price 10
server.addUser("Petar", "pass123", UserType::Pro);   // id 2, price 100

server.deleteUserByID(1);                            // remove Gosho
std::cout << server.getTotatalMonthlyRevenue();      // 100  (0 + 100)
```

---

## Extension ideas

1. Use the singleton from Task 1 as a shared id-generator service instead of a per-class static counter.
2. Replace the fixed-size raw array in the server with a dynamic container of smart pointers.
3. Allow new user kinds to be plugged in **without modifying** the existing creation logic.
4. Add a globally accessible logger that records every user creation and deletion.
