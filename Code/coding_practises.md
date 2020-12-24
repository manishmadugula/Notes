# C#
- Avoid using boolean arguments to define alternative behavior for your functions. Same function shouldn't do 2 different things based on a boolean flag.
- Reduce the number of parameters by combining related parameter into an inner class maybe. Maybe 3 parameters per function.
- Don't return null if the items are empty, return an empty collection instead.
- Having out in the function arguments is code smell, simply return a result object instead.
- Tuples are code smells, better to have a separate class to define what each property is.
- Declare the variable where they are used, not at top. So the user has to use less brain power.
- Before refactoring always ensure you have unit and integrated test cases
- Don't use magic numbers or magic strings. Instead use Enums/ Constant Integer fields.
- Avoid nested conditionals
  - Use ternary operators
  - Use logical opertors to combine conditions
  - Wrap complicated conditional logic into functions.
  - Simplify true/ false
    ```c#
    if(customer.TotalOrder > 50)
        isGoldCustomer = true;
    else
        isGoldCustomer = false;
    ```
    can be converted to 
    ```c#
        isGoldCustomer = customer.TotalOrder > 50;
    ```
    - Make sure there are no redundant conditionals
- Avoid switch clauses and replace with inherited classes/polymorphism.