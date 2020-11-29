# C#
- Avoid using boolean arguments to define alternative behavior for your functions. Same function shouldn't do 2 different things based on a boolean flag.
- Reduce the number of parameters by combining related parameter into an inner class maybe. Maybe 3 parameters per function.
- Having out in the function arguments is code smell, simply return a result object instead.
- Tuples are code smells, better to have a separate class to define what each property is.
- Declare the variable where they are used, not at top. So the user has to use less brain power.
- Don't use magic numbers or magic strings. Instead use Enums/ Constant Integer fields.