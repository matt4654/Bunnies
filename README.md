# Bunny Project - C++

Tracks the population of bunny objects as they age, breed, die, and become infected within a field object.

## Goals

> * List of bunnies 

Bunny Attributes:

> * Sex: Male/Female
> * Colour: White, Brown, Black, Spotted
> * Name
> * Age
> * Infected: True/false

Functionality:

> * Sex 50/50 at creation
> * Name randomly selected from list at creation
> * Infected 2/98 at creation
> * 5 bunnies created at program initialisation with random colours
> * Bunnies age 1 year per turn
> * If there's at least one male >2 years old, each female >2 years old births a bunny of the same colour
> * Noninfected bunnies can't live past 10 years old
> * Infected bunnies infect 1 noninfected bunny per turn
> * Infected bunnies don't breed
> * Infected bunnies can't live past 50 years old
> * Each turn should print out all bunnies' information sorted by age
> * Each turn should print out all the turn's events (e.g. Bunny Bob was born!)
> * Program terminates when all bunnies are dead
> * If the population exceed 1000, a random half of the population is killed.


## Description

A default `bunny` constructor `bunny()` initialises a `bunny` object to have `age = 0` and a random `id`, `name`, `sex`, `colour`, and `isInfected`. The random `name` is selected from a list of names contained within _exampleNames.txt_.

The constructor `bunny(const std::shared_ptr<bunny>&)` works the same as `bunny()` but assigns a `colour` the same as the argument `bunny`'s `colour`.

When a `field` object is instantiated, `bunny()` is called 5 times and each `bunny` is added to the `field`'s list of bunnies `bunnies`.

The most significant method of `field` is `bunnyLifeCycle()`. It aims to implement as much functionality in one iteration of `bunnies` to increase efficiency. Since `bunnies` will be sorted by descending age, the death conditions are checked first. If not killed, birthing conditions are checked, then infection conditions, then the `bunny` is aged 1 year. The bunnies that were born, killed, and infected are added to respective pre-emptied lists owned by the `field` for later printing of events.

Since there was no specified rule for which particular bunnies become infected, it was decided to infect the oldest bunnies first because this is more efficient and makes more sense conceptually. (The choice of which bunnies become infected has consequences for the dynamics of the system).

To kill a random half of the population, the `field` method `killHalf()` sorts `bunnies` by the randomly-assigned `id`'s then erases the first half of the list.

In `main()`, the `field` method `turn()` is looped while the number of bunnies is >0, with a condition that calls `killHalf()` if the number of bunnies is >1000