# Cocos2dx-GUI-unit-testing

In my youtube channel: https://www.youtube.com/channel/UCjDVZ7PHvbp-G_pkVW-yrqw there is an entire video where I create this code. This repository primarily exists as a "hardcopy" of the code from that video.

This is a fairly terse example of how to set up GUI unit testing within a cocos2d-x. While unit testing rocks and has pretty much become a staple of all my development I found that testing the GUI was sort of something that wasn't really doable. Many people will stress that if you are using an MCV architecture that if you are unit testing the Model and the Controller that the View can sort of be left out. 

Well that is where many of my projects have run into interesting problems. Things such as the GUI not being happy with certain Unicode strings, or the sound engine not happy when I play 3 simultaneous sounds instead of the usual 2. Or any one of a zillion other little kinks that were either bugs in the GUI/multi-media-engine or were simply me using it wrong and pushing it past its known limits.

So I tried many solutions to this problem and while the problem was not hard to solve it was hard to solve with any elegance. One of the rules with unit testing is generally if it isn't very elegant then it may end up being more work than it is worth.

# Catch.hpp
So here is my present day solution to unit testing a Cocos2d-x application using the catch.hpp single file header only library.

The key to this solution is that the catch.hpp doesn't demand that it run its own main() function to initiate unit testing. This allows me to delay the beginning of unit testing until after Cocos2d-x has done its thing. Once the director has a placeholder scene running then I initiate the testing. 

Catch.hpp is my present favourite testing framework. Elegance is definitely where it rocks. Being a single file header only library, integration is a dream. You include it and with a single define I am pretty much done. The macros are typical of a unit testing framework and are clean. 

One massive advantage of this elegant simplicity is that with Cocos2d-x I am developing multi platform. This means that any libraries or code added needs to be easily integrated with each of the platforms' slightly varying codebases; with Android being the most fussy. Catch.hpp does this in spades.

# Cocos2d-x

As for cocos2d-x it is simply the best damn multimedia multi-platform environment around. It is tight, rapidly improving, covers all the bases, and just works. I don't spend much time fighting with cocos2d-x. There are certainly more robust environments out there such as Unreal which from a checklist point of view blow cocos2d-x out of the water. Except that for the scale of projects that I presently work on they are more effort for not enough gain(at this point).

# How this works

A unit testing target has been setup for the desktop. It is a duplicate of the desktop target. This has a preprocessor macro variable added called UNIT_TESTING so that ifdef conditionals can be added to code that will only compile for the unit testing target.

A Duplicate of the AppDelegate is created called TestDelegate. The TestDelegate is a member of the new unit testing target while AppDelegate is removed from the unit testing target.

A TestScene class is created which is a stripped down HelloWorldScene. This is a placeholder for the Director to run as it will do nothing but produce a blank screen.

The TestDelegate is redirected away from HelloWorldScene and pointed to run TestScene at startup.

The TestDelegate is where the Unit testing will take place. The TestDelegate is certain to keep running while the Director does whatever it wants to various scenes that come and go. All catch.hpp is inserted into the TestDelegate class.

A CommonCrap.h file is created to contain a namespace with a few singletons. One singleton will contain a pointer to the main layer of the scene that is presently running. The second singleton will contain an index to the class type of the layer presently running.

Each scene will send to the commoncrap singletons a pointer to the layer class and the layer class type. 

Each unit test can then make member function calls to the presently running layer so as to initiate unit tests. If the member function calls change the presently running scene the new scene layer can be obtained along with its class type. 

#This example

This fairly crude example of the above uses HelloWorldScene as the primary scene and SceneOne, SceneTwo, SceneThree as other scenes. There is one button on each screen which will randomly replace the scene with one of the three numbered scene types. The unit testing follows along and makes calls to this button which has different member function names depending upon the class.

# Why

I hope that this helps anyone who is stuck trying to figure out how to test their cocos2d-x gui based application. I know that there aren't any really good examples that I could find.

#Code
Don't rain hate on my code. This code is very much the minimal amount of code to show the path to unit testing. I probably leave a trail of memory leaks and nothing is safety checked. I don't even unit test so much as get the unit testing to make the gui dance. I could have made the code better but then it would be less a lesson on gui unit testing and more a lesson on solid coding. There is pretty much nothing here that wasn't the minimum path to a proof of concept.

#Using this project

To use this project create a HelloWorld project:

cocos new Unittesting -p com.lessonstudio.unittesting -l cpp -d /Users/Donovan/Documents/programming_experiments/

and then overlay the code in the Unittesting directory in this repository over that project. 
