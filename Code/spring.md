# Spring Advantages
- Spring is just a dependency injection framework.
  - Makes classes free from headache of managing dependency
  - Helps writing testcases easier
- Additionally Spring focuses on the "plumbing" of enterprise applications so that teams can focus on application-level business logic, without unnecessary ties to specific deployment environments.
  - Reduce plumbing code of JDBC, JMS
  - Good integration with popular frameworks hibernate etc.

# Spring Boot Advantages
- Spring had a lot of configurations
  - Beans
  - Dispatcher Service, View Resolver, Error Handling etc.
- Shift to microservices, so quickly start developing applications
  - Spring boots makes it easy to create production grade application and deploy quickly.
  - It is spring with default configuration
  - It tries to auto configure a lot of stuff.
- Provides embedded server, health checks, security metrics etc.




# Inversion of Control In Spring
- One of the main features of the Spring framework is the IoC (Inversion of Control) container. The Spring IoC container is responsible for managing the objects of an application. It uses dependency injection to achieve inversion of control.
- The interfaces BeanFactory and ApplicationContext represent the Spring IoC container. Here, BeanFactory is the root interface for accessing the Spring container. It provides basic functionalities for managing beans.

## Auto Wiring
- Mechanism to perform dependency injection

## Spring Container
- The Spring container is responsible for instantiating, lifecycle, configuring, and assembling the Spring beans.

## Types of IOC Containers in Spring
- BeanFactory and ApplicationContext and WebApplicationContext
### Bean Factory
- This is the root interface for accessing the Spring container.
- Usually, the implementations use lazy loading, which means that beans are only instantiating when we directly calling them through the getBean() method.
### Application Context
- The ApplicationContext is the central interface within a Spring application that is used for providing configuration information to the application.
- It implements the BeanFactory interface. Hence, the ApplicationContext includes all functionality of the BeanFactory and much more! Its main function is to support the creation of big business applications.
####  Responsibilities:
- Bean instantiation/wiring
- Automatic BeanPostProcessor registration
  - ?
- Automatic BeanFactoryPostProcessor registration
  - ?
- ApplicationEvent publication
  - ?
- Convenient MessageSource access
    - ?

#### Application Context Types
- AnnotationConfigApplicationContext
  - It can take classes annotated with @Configuration, @Component, and JSR-330 metadata as input.
- AnnotationConfigWebApplicationContext
  -  similar to AnnotationConfigApplicationContext, the only difference is it is build for web application. Spring by default calls XmlWebApplicationContext.
- XmlWebApplicationContext
    - loads context definition from an XML file contained within a web application.
- FileSystemXMLApplicationContext
  - loads context definition from an XML file in the filesystem.
- ClassPathXmlApplicationContext
  - loads context definition from an XML file located in the classpath

- Don't use any of these use spring boot which figures by itself.

## Library vs Framework
- The technical difference between a framework and library lies in a term called inversion of control.
- When you use a library, you are in charge of the flow of the application. You are choosing when and where to call the library. When you use a framework, the framework is in charge of the flow.

## DI vs IOC vs Service Locator
### IOC
- IoC is a generic term meaning that rather than having the application call the implementations provided by a library (also know as toolkit), a framework calls the implementations provided by the application.
- IoC is much more than object creation: a Spring Context or a Servlet Container not only create objects, but manage their entire lifecycle. That includes creating objects, destroying them, and invoking certain methods of the object at different stages of its lifecycle. These methods are often described as callbacks.
### DI 
- DI is a form of IoC, where implementations are passed into an object through constructors/setters/service lookups, which the object will 'depend' on in order to behave correctly.
- Very useful for implmenting Unit Test cases.
- This helps you to follow SOLID’s dependency inversion and single responsibility principles.

## Types of DI
### Constructor Injection
- Constructed object is immutable and returned to the client in a fully initialized state.
- Higher chance to have circular dependencies, so-called chicken-and-egg scenario.
```java
@Autowired
public DependentService(Service1 service1, 
            Service2 service2){
    this.service1 = service1;
    this.service2 = service2;
}
```
### Property Injection/ Field Injection
- Easy to use, no constructors or setters required
- No immutability — the same as for setter injection.
```java
@Autowired
private Service1 service1;
```
### Method Injection/ Setter Injection
- Flexibility in dependency resolution or object reconfiguration, it can be done anytime. Plus, this freedom solves the circular dependency issue of constructor injection.
- Null checks are required, because dependencies may not be set at the moment.


```java
@Autowired
public void setService2(Service2 service2) {
    this.service2 = service2;
}
```
### Interface Injection
- Spring does not support it
# Modules of Spring


## Modules of Spring Core




# Annotations

## Spring Annotation

@Component

@Service

@Repository

@ComponentScan

@RestController
  - Tell Spring the current class is a rest controller
  - It has ResponseBody annotation in it so the response will be directly sent back to browser and not to view resolver.

@RequestMapping
- Specify the url and method which will trigger the below method

@GetMapping
- Specify the url which will trigger the below method

@PathVariable

@RequestBody

@Autowired
- Inject by type.

@Controller 
- Doesn't have responseBody in it.
- Controller is also a Component.

@Bean
- The method will return a bean.

@Configuration 
- The class with @Configuration becomes the configuration class.
- Sample spring configuration class
```java
@Configuration
public class SwaggerConfig {
    //Return a Bean of type Docket
    @Bean
    Docket getDocket(){
        return new Docket(DocumentationType.SWAGGER_2);
    }
}
```


@Import 

@Qualifier

@ResponseBody
- the response will be directly sent back to browser and not to view resolver.

@Response Status

@ControllerAdvice

@JsonIgnore

@Repository
- Component which interacts with DB.

## Spring Boot Annotations
@SpringBootApplication
- ComponentScan runs in same package

## JPA Annotations
- See java_microservies.md

# LifeCycle Hooks

## Bean vs Servlet vs POJO

### POJO
- A POJO has no naming convention for our properties and methods.
- But, we aren't following any real convention for constructing, accessing, or modifying the class's state.
- This class can be used by any Java program as it's not tied to any framework

### Bean
- Spring beans are Java objects that are managed by the Spring container.
- All JavaBeans are POJOs but not all POJOs are JavaBeans.
- A JavaBean is basically a Java class which satisfies a few simple rules
  - Serializable i.e. they should implement Serializable interface. Still, some POJOs who don’t implement Serializable interface are called POJOs because Serializable is a marker interface and therefore not of much burden.
  - Fields should be private. This is to provide the complete control on fields. Since if the field is not private anyone can change it to invalid value.
  - Fields should have getters or setters or both.
  - ### A no-arg constructor should be there in a bean.
  - Fields are accessed only by constructor or getter setters.
  - Getters and Setters have some special names depending on field name. For example, if field name is someProperty then its getter preferably will be ```getSomeProperty()```
  - If you don't have getters and setters in the Bean you will face a response.

### Servlet
- a servlet specifically subclasses javax.servlet.Servlet and/or javax.servlet.http.HttpServlet and implements one or more of the doXXX methods.




## Bean Scope
-
- Default Scope is Singleton



## Dispatcher Servlet vs Request Dispatcher
### Dispatcher Servlet
- It is the front controller
- Looks at the url and sends to the right controller and method.
- Also sends the response to view resolver if required if there is no response body.
- Handles all the requests


# AutoConfiguration
- Looks at the classes and jar in class path and configures different classes, like JacksonObjectMapper(Json to object and vice versa), error configuration, dispatcher servlet. 

# REST USING SPRING BOOT

## Return a JSON Object
- Automatically handled by jackson json
- ### The returned Object has to be a valid Spring Bean, i.e with public setters and getters else there will be exception

## Submit Query Parameters in Spring Boot
- You need to use ```@PathVariable``` annotation.
- Your route should also have the variable with same name, else you will get error in the response.
```java
  @GetMapping(path = "/hello-world-bean/user/{yourName}")
  public HelloWorldBean helloWorldBeanPathVariableExample(@PathVariable String yourName){
      return new HelloWorldBean("Hello World Bean" + yourName);
  }
```

## Throw Exception in Spring Boot
- You should implement the RuntimeException which is an unchecked exception.
- Also to get 404 Error Code Add the ResponseStatus Annotion in the Exception
```java

@ResponseStatus(HttpStatus.NOT_FOUND)
public class UserNotFoundException extends RuntimeException {
    public UserNotFoundException(String s) {
        super(s);
    }
}

@GetMapping("/users/{id}")
public User getUser(@PathVariable Integer id){
    User user = userService.findUser(id);
    if(user == null){
        throw new UserNotFoundException("id : " + id);
    }
    return user;
}
```

## Validation in Spring Boot
- Use @Valid annotation
```java
public ResponseEntity createUser(@Valid @RequestBody User user)
```
 with following constraints
```java
@Size(min=2)
private String name;

@Past
private Date birthDate;
```
- Following are the various constraints

![](res/validation_constraitns.jpg)


## Create a object with Spring Boot
- You need to use ```@RequestBody``` annotation
- It is best practise to return the URI of the created resource, no need to send all the information related to created user since that just wastes the bandwidth.
- To just send the URI of the created resource, we can send the URI in the location portion of the header.
- To perform this you need to return the location information in the ResponseEntity Object. It has a created method which expects a URI, you can create the URI using the ServletUriComponentBuilder;
```java
@PostMapping("/users")
public ResponseEntity createUser(@RequestBody User user){
    User savedUser = userService.save(user);

    URI location = ServletUriComponentsBuilder.fromCurrentRequest()
            .path("/{id}")
            .buildAndExpand(savedUser.getId()).toUri();

    return ResponseEntity.created(location).build();
}
```

## Monitoring APIs
- Using Spring Actuator and HAL Explorer
- Lots of useful metrics and properties about the Spring Application
  - All the created Beans
  - health checks
  - Postive and Negative match on condition for Auto Configuration
  - Environment
  - Heap Dump
  - Thread Dump
  - Metrics
    - Amount of memory used etc.
    - CPU Usage
    - JDBC Connections Active
    - GC Information

## Swagger API Documentations
- You can document the API for the consumers in a very structured way using swagger.
- It also enables you to document the constraints on the properties expected by each API.
- Document the request type which are accepted (json/xml) and also the response type (json/xml)


## Hypermedia as the engine of application state (HATEOS)


## Content Negotiation is the ability to send both xml and json responses
  - Use jackson xml

## Filter the attributes to be sent in the response
### Static Filtering
- You can decorate some fields as ```@JsonIgnore``` so they won't be sent in the response as a JSON Object, like say a password field
- Be careful there are multiple implementation of JsonIgnore, use fasterxml.jackson
```java
import com.fasterxml.jackson.annotation.JsonIgnore;
public class SomeBean {
    private String one;

    @JsonIgnore
    private String three;

    public SomeBean(String value1, String value3) {
        one = value1;
        three = value3;
    }

    public String getOne() {
        return one;
    }

    public void setOne(String one) {
        this.one = one;
    }

    @JsonIgnore
    public String getThree() {
        return three;
    }

    public void setThree(String three) {
        this.three = three;
    }
}
```
### Dynamic Filtering based on the request.


## Versioning

### URL Based Versioning
- Polluting URL Space
- Documentation is easier
#### URI Based Versioning
```java
@GetMapping("/v1/person")
PersonV1 getPersonVersion1(){
    return new PersonV1("Manish Madugula");
}

@GetMapping("/v2/person")
PersonV2 getPersonVersion2(){
    return new PersonV2(new Name("Manish","Madugula"));
}
```
#### Parameter Based Versioning
```java
@GetMapping(value = "/person", params = "version=v1")
PersonV1 getPersonVersion1Param(){
    return new PersonV1("Manish Madugula");
}

@GetMapping(value="/person", params = "version=v2")
PersonV2 getPersonVersion2Param(){
    return new PersonV2(new Name("Manish","Madugula"));
}
```


### Header Based Versioning
- Misuse of HTTP Header
- Caching is not straightforward, since we also need to look at header and do complicated stuff with it, not simply see if URL are same
- Cannot execute directly in browser, need POSTMAN etc.
#### X-API-VERSION
```java
@GetMapping(value = "/person", headers = "X-API-VERSION=v1")
PersonV1 getPersonVersion1XAPI(){
    return new PersonV1("Manish Madugula");
}

@GetMapping(value="/person", headers = "X-API-VERSION=v2")
PersonV2 getPersonVersion2XAPI(){
    return new PersonV2(new Name("Manish","Madugula"));
}
```
#### Accept Header/Produces Param/MIME Type Versioning/Media type Versioning/Content Negotaition
```java
@GetMapping(value = "/person", produces = "application/com.madmanish.restfulwebservices-v1+json")
PersonV1 getPersonVersion1ContentNegotation(){
    return new PersonV1("Manish Madugula");
}

@GetMapping(value="/person",  produces = "application/com.madmanish.restfulwebservices-v2+json")
PersonV2 getPersonVersion2ContentNegotation(){
    return new PersonV2(new Name("Manish","Madugula"));
}
```

# Important Jars
- spring-boot-starter-web
  - Starter for building web, including RESTful, applications using Spring MVC. Uses Tomcat as the default embedded container
- spring-boot-starter-data-jpa
- spring-boot-starter-security
  - Handles Spring Security OAuth, Basic Validation etc.
- spring-boot-starter-validation
  - Handles Constraints on the Request Body and Parameters by setting up validation logic.
- spring-boot-starter-actuator
  - Monitoring spring application
- spring-data-rest-hal-explorer
  - UI tool too see the monitoring data
- spring-boot-devtools
  - Live Load
- spring-boot-starter-test
  - Test framework for spring
- springfox-swagger2
  - API Documentation in JSON
- springfox-swagger-ui
  - API Documentation Visualize in UI

# In 28 Minutes
- Service Defination
  - Contract between both the services.
  - Request, Response Format and Structure and endpoint.
  - Example: Swagger

- Jackson
  - Converts to JSON and Back
- ServletUriComponentBUILDER
- ResponseEntity
- ResponseEntityExceptionHandler

# Old Notes
- Lifecycle hooks vs constructor
- For prototype scope, spring doesn't call the destroy-method hook (In contrast to the other scopes, Spring does not manage the complete lifecycle of a prototype bean:), however you can create your own custom bean processor to call destroy even for prototype scopes.
- Read about BeanPostProcessors
- You can use any method for setter injection while using component scanning via annotations.
- Autowired annotation should only be used on a single constructor, the one which spring will use to create the instance.
- Autowired annotation can be used with multiple setter methods/ random methods name.
- Qualifier annotation can be used to tell spring which implementation to inject, in case of multiple injections, it should be applied to individual fields/parameters not as a whole to constructor.
- **If the annotation's value doesn't indicate a bean name, an appropriate name will be built based on the short name of the class (with the first letter lower-cased). Except for the special case of when BOTH the first and second characters of the class name are upper case, then the name is NOT converted. Example For the case of RESTFortuneService, it is not converted to rESTFortuneService, you need to explicitly name it.**
- So think of the @Bean annotation was a wrapper / adapter for third-party classes. You want to make the third-party classes available to your Spring framework application context. Unlike the XML Application Context which requires you to specify @Component in your class, using @Beans you don't need to modify the class that you want to include in your IOC container/Application context. You can use @Bean to make an existing third-party class available to your Spring framework application context.
- In spring the front controller(Created by spring dev team) is called DispatcherServlet and it will delegate the request to the controller.
- View template common are JSP(Java Server Pages and JSTL)
- Look at spring config files again for mvc.
- When performing Spring MVC validation, the location of the BindingResult parameter is very important. In the method signature, the BindingResult parameter must appear immediately after the model attribute. 
- @Valid performs the validation on the model attribute, and stores it in BindingResult.