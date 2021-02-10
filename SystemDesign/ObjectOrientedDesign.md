# Basic Tips
- Remember to add unique_identifiers to entities.
- Clarifying requirements is very importants.
- Singleton for the entire system
- Add monitoring like logs for almost all systems.
- Identify useless classes, like vehicles in parking lot and person in elevator system design.(We are trying to control system not simulate it).
- There is probably going to be a strategy pattern in all the problems just mention it.
- Enumeration violates open-closed principle, so use enumeration only when you know no other types would be used in future.
- Add analytics module for every design.
# Parking Lot

## System Requirements
- general design, should be used for code reusability.
### Architecture
- Multiple floors
- Multiple entry and exits.
- Collect the ticket at entry
- If max capacity is reached, system should not allow more cars.
### Payment
- Pay at exit
- Pay using cash and credit card/paytm
- payment should be based on per hour parking fees.(customers have to pay $4 for the first hour, $3.5 for the second and third hours, and $2.5 for all the remaining hours.)
### Parking spots
- Many parking slots per floor
- Types of parking spots compact, large, handicapped, motorcycles
- System should show free parking spot for each type.

## Actors
- Admin (adding/removing floors, parking spots, parking attendents)
- Parking attendent (assigning a ticket with parking spot, take cash payment)
- Customer (Get a parking ticket and pay for it)
- System (Display the info on the panel, assign and remove a vehicle from the spot)

## Use Cases
- Take Ticket
- Pay Ticket

- Add/remove floors
- Add/remove parking spots
- Add/remove the parking attendant
- Assign/ Unassign the car to parking spot (nearest).

## Design patterns and algorithms to use
- Singleton for parking lot.
- Strategy pattern to find the nearest free parking spot. 
  - Min heap approach/shortest path algorithm.
  - Also would require concurrency in case of multiple entrances/exit scenario.
- AOP for monitoring/logging (subscribing to events).


## Diagram
![](res/ood_parking_lot.jpg)


# Elevator System
- Multiple floors, and elevators
## Actors
- Dispatcher Service
  - To optimize waiting time or throughtput or power etc. (Use strategy pattern here)
  - FCFS.
- Floor
- Lift
- Button
  - Elevator Buttons (goUp/goDown will do very different things)
  - Hall Buttons
- Door
- Monitoring System
## Use Cases
- Calling the elevator
- Move/ Stop the elevator.
- Indicate the elevator positiion.
- Emergency breaks.
- Emergency calls.

## Dispatcher/Scheduler
- Similar to OS.
- There is request queue.
### Algorithms
- Make sure there is no starvation
- Start going in the direction of the first button pressed, keep track of which direction we're going.
- When a floor is reached and that button was pressed, stop and open the doors, mark the buttons for this floor as not pressed anymore.
  - If there are still more floors that we need to visit that are in the same direction, keep going in that direction.
  - If not and there are still floors we need to visit, move in that direction.
  - If not then we're done and will start at 1 when a button is pressed again.
#### FCFS
- State of Elevator Car can be
  - Idle
  - Moving in direction towards the passenger and same as the direction passenger wants to go. (Might also be in opposite direction as passenger initially then become idle before coming into contact with passenger)
  - Moving in the direction towards the passenger and opposite to the direction passenger wants to go.
  - Going away from passenger.
- Disadvantage of this approach
  - All the other user will be blocked till the first user is served.
  - Useless elevator motion up and down

#### Look Ahead algorithm.
- Use a tree to see if there are any request to the top or down.

#### StackOverflow
"Efficiency" is not the most important feature, the most important is to make sure every order is followed, that there is no starvation. If someone presses 100 and people keep pressing 1 and 2 it may be efficient to keep going between those floors, but it'd be nice for 100 to be visited at some point.

I think (from personal observation when I was interested in figuring out) that most of them do:

Start going in the direction of the first button pressed, keep track of which direction we're going
When a floor is reached and that button was pressed, stop and open the doors, mark the buttons for this floor as not pressed anymore.
If there are still more floors that we need to visit that are in the same direction, keep going in that direction.
If not and there are still floors we need to visit, move in that direction.
If not then we're done and will start at 1 when a button is pressed again.
Note that many elevators have buttons "I want to go up" and "I want to go down" next to the doors instead of a single button. The algorithm only needs a small change: in 2, if the only button pressed for that floor is one of the buttons next to the door, only stop and open the doors if we are going in that direction. Possibly keep the button pressed if the doors open because of a button pressed inside the elevator and it is going in the wrong direction.

You never have to figure out an entire path, just in which direction to go next.

# Online Shopping System
- 