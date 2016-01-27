# rebergen
A Reber grammar/embedded Reber grammar generator.

## Background
### What's A Reber Grammar?
A Reber grammar is an artificial grammar which generates a sequence of letters. The grammar works in such a way that the end characters of the grammar will depend on which characters were chosen near the start of the grammar, which can make it a good way of modelling a long range pattern.

A Reber grammar looks like this:

![Reber Grammar](./ReadmeGraphics/reberGrammar.png?raw=true "The Reber Grammar")

An embedded Reber Grammar looks like this:

![Embedded Reber Grammar](./ReadmeGraphics/embeddedReberGrammar.png?raw=true "The Embedded Reber Grammar")

### Why Do You Need One?
#### More Background - Recurrent Neural Networks and Backpropagation
Recurrent neural networks are neural networks where some output of the network at time step t is fed back into the network for processing at time step t+1.

A deep neural network is a feedforward neural network with a lot of hidden layers.

Training these networks is done using the backpropagation algorithm. Unfortunately, backpropagation stops working properly after enough layers - it works from output to input, propagating the error term backwards through all neurons in the network. The gradient of the error function with respect to the weights of the neurons must be taken in order to perform gradient descent optimisation, but the propagation process involves repeated multiplication of this gradient which can, in short, make it either vanish to nothing (vanishing gradient problem) or explode into a very large/undefined value (exploding gradient problem).

This stops the early layers from learning quickly or at all.

#### How Does This Grammar Come In?
The Reber Grammar, and its cousin the Embedded Reber Grammar, are good ways of testing the ability of a recurrent neural network to learn long-range dependencies. Traditional (i.e. the neurons are just shoving a weighted sum of inputs through an activation function) recurrent neural networks are fine with Reber grammars, but fail on embedded Reber grammars. If a recurrent neural network is purported to be able to learn long-range dependencies, the embedded Reber grammar is a good corpus generator and a good result checker.

## Implementation
This is written in C++, and is pointlessly object oriented because it's a nice learning exercise. General structure: each node in the chain is a reberNode object. A whole Reber Grammar will be a reberGrammar object, which should inherit reberNode because I want it to plug nicely into a bigger Reber Grammar to make an embedded Reber Grammar. I have no idea if it's going to work though, so this may well change. 


