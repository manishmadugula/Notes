# Maven
- See some videos about maven pom file.

## POM File (Project Object Model)
### Parent
```xml
<parent>
    <groupId>mycompany.trade.com</groupId>
    <artifactId>mycompany.trade.</artifactId>
    <version>1.1.1.0-SNAPSHOT</version>
</parent>
```
- maven reads the parent POM from your local repository (or proxies like nexus) and creates an 'effective POM' by merging the information from parent and module POM.
-  reason to use a parent is that you have a central place to store information about versions of artifacts, compiler-settings etc. that should be used in all modules.

# JUnit
- See how to write test cases in JUnit.
- Test driven code is writing testcase first and then write the code to pass those test cases.

# JDBC
- JDBC is a standard for connecting to a DB directly and running SQL against it 

# JPA
- Java Persistence API
- JPA is a standard for Object Relational Mapping. The most famous JPA provider is Hibernate. 
- JPA is an specification/interface and Hibernate is an implements of the JPA Specification

## Entity Manager
- Save the Entity to Database

## Persistence Context
- The persistence context is the first-level cache where all the entities are fetched from the database or saved to the database. It sits between our application and persistent storage.
- An EntityManager instance is associated with a persistence context.
- Flushing a Cache is the act of putting modified data back into the database.
- A PersistenceContext is essentially a Cache. It also tends to have it's own non-shared database connection.
### Persistence contexts are available in two types:
- The default persistence context type is PersistenceContextType.TRANSACTION. To tell the EntityManager to use the transaction persistence context, we simply annotate it with @PersistenceContext
#### Transaction-scoped persistence context
- The transaction persistence context is bound to the transaction. As soon as the transaction finishes, the entities present in the persistence context will be flushed into persistent storage.
####  Extended-Scoped Persistence Context
- An EntityManager using an extended persistence context maintains the same persistence context for its entire lifecycle. Whether inside a transaction or not, all entities returned from the EntityManager are managed, and the EntityManager never creates two entity instances to represent the same persistent identity. Entities only become detached when you finally close the EntityManager (or when they are serialized).



## Annotations

@Entitiy
- Store a Java bean to the table then declare the bean with the Entity Annotation.

@Id
- Declare primary key with Id Annotation

@GeneratedValue
- Declare the field decorated by this annotation to have generated value.

@Transactional
- Each method would be involved in a transaction if the class is declared with @Transactional annotation.
- It is used to combine more than one writes on a database as a single atomic operation.
- If you don't specify @Transactional, each DB call will be in a different transaction.
```java
@Repository
@Transactional
public class UserRepository {
    @PersistenceContext
    private EntityManager entityManager;

    public long insert(User user){
        entityManager.persist(user);
        return user.getId();
    }
}

```


@PersistenceContext

# Apache commons
- It has utility classes.

# Domain Driven Design
- Eric Evans
- We develop model of the domain/business problem and make our software conform to that.
- When designing our focus shouldn't be on the technology, but on the business or whatever activity we are trying to assist with the  software.
- It's not customer's job to know what they want. Even if architecture is fabulous but the end user decides if the system is good or not.
- Services, Entities, Domain Model, Repositories, Factories are made popular by domain driven design
## 2 Types of tools

### Strategic Design Tools
- Everyone who is more experienced will give more importance to strategic design tools.
- Instead of thinking in terms of objects like in OOPs, we think in terms of context (setting in which a word/statement appears, determines it's meaning)
- When given a problem, you talk to domain expert and try to find the core values and motivation behind each feature.
![](res/ddd.jpg)
- Shouldn't change during product development.
#### Domain Model
- Aspects chosen for implementation that constitute the model.
- Representation of Bounded Contexts, Domain Model is to Bounded Context, what classes are to objects.

#### Ubiquitous Language
- Developer, Domain Expert, Analyst, everyone and everything should use the same words for same concepts, any 2 people are talking to each other, everyone else should be able to follow. You need to name your classes, code, documentation that way. Don't become more technical that necessary.
- ![](res/ubiquotous_language.jpg)
#### Bounded Context
- Things hold the same meaning within each bounded context.
- In the following figure, A Customer Concept is different to a Sales Person(Interests, likes, needs) and is different to Support(Purchase History, Tickets etc) and also different for Accounting(Method of Payement, Refunds etc). Each of these are a bounded contexts.
- **Each bounded context needs to have their own Domain Model and Bounded Context, Database, API, User Manual.**
- Design your microservice around bounded context.
![](res/bounded_context.jpg)
#### Context Map
- Relationship between bounded context, API Contracts etc are context map.

#### Event Storming
- Brainstorming workshop between domain experts and developers aimed to attain a common understanding of the domain model and define bounded contexts etc.

### Technical Design Tools
- Concerned with the implementation
- Expected to change within product development.
![](res/ttt.jpg)
#### Layered Architecture.
- The heirarchy of Request Handler, Controller to Service Layer and Finally to Repository Layer.
- Everything is organised and well design, reusable components.

#### Value Objects
- Don't use primitive in your code.
- Value enforces ubiqutous language.
- Easily Validate/Limits inside the value itself.
- Helps us avoid Magic Numbers and duplicated code.
- Immutable so thread safe.
![](res/value_objects.jpg)
![](res/ddd2.jpg)


#### Entity Object
- Uniquely Identified using ID
- Consists of value objects
- mutable
- represents a row in db.
- generally implements some business logic

