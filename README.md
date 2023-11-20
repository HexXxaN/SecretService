# SecretService
A simple 2D arcade game 

This game was created for a university assignment. 
The player can choose to play one of two agents:

`Agent A: once a game can increase its speed for 2 seconds`

`Agent B: once per game can become invisible for 2 seconds`

The current objective of the game is to avoid enemies. Other objectives may appear in the future.
The enemies can detect the player radially, and once the player has been detected each enemy agent gets the player location and chases the player immediately.
The enemies cannot see through obsticles, and when the player is not detected they can only move on pavements and inside the buildings.

# Windows

To run the game on Windows simply download the Release file, go to windows subfolder and run SecretService.exe

# Linux

To run it on a Debian-based Linux distro, make sure you have installed git, cmake, libsdl2-dev, and libsdl2-image-dev:

```
sudo apt update
sudo apt install git
sudo apt install cmake
sudo apt install libsdl2-dev
sudo apt install libsdl2-image-dev
```

Once you've installed everything, simply clone the repository to a directory of your choice:
```
git clone https://github.com/HexXxaN/SecretService
```
After you've cloned the repository, move to its directory:
```
cd SecretService/
```
Now you have to make a build folder:
```
mkdir build
```
Move to that folder:
```
cd build/
```
And run the cmake:
```
cmake ..
```
Now build the source files:
```
cmake --build .
```
If everything went correct, you should be able to launch the game by typing in the terminal:
```
./secret-service
```
Enjoy!
