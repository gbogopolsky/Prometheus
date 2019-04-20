# Prometheus

## Presentation

Simulation of the trajectory of a spaceship in space. The thrust is a direct input from the arrows of the keyboard, the trajectory is computed in real time with a RK4 solver, all of this in a simple GUI made with SFML.
Planets are randomly generated, and the player can decide if the referential is the surrounding space or the spaceship.

## Launch

Use `Meson` and `ninja` to build the project as follows:

```bash
meson build
cd build
ninja
./sfml-app
```

Make sure that `libsfml` is installed.
