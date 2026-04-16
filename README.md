# Black Hole Simulation

A real-time null geodesic integrator visualizing photon paths around a Schwarzschild black hole.
Built in Taichi Lang. All physics is derived from first principles using the Euler-Lagrange formalism.

![Status](https://img.shields.io/badge/Status%3A-Active-brightgreen?style=for-the-badge)
![Langauge](https://img.shields.io/badge/Language%3A-Python-blue?style=for-the-badge)
![Physics](https://img.shields.io/badge/GR-Schwarzschild-orange?style=for-the-badge)

## Table of Contents

- [Project Overview](#project-overview)
  - [The Mission](#the-mission)
  - [Executive Summary](#executive-summary)
  - [Video Demo](#video-demo)
- [Quick Start](#quick-start)
  - [Installation](#installation)
  - [Running the Simulation](#running-the-simulation)
- [Scientific Background](#scientific-background)
  - [Relativity 101](#relativity-101)
    - [The Core Concept](#the-core-concept)
    - [The Null Geodesic](#the-null-geodesic)
    - [The Point of No Return](#the-point-of-no-return)
  - [Mathematical Framework](#mathematical-framework)
    - [Lagrangian Formalism](#lagrangian-formalism)
    - [Conserved Quantities](#conserved-quantities)
    - [Radial Equation](#radial-equation)
    - [Photon Sphere](#photon-sphere)
  - [Key Phenomena](#key-phenomena)
    - [Time Dilation](#time-dilation)
    - [Gravitational Redshift](#gravitational-redshift)
- [Further Reading](#further-reading)
  - [Math and Physics Explained](#math-and-physics-explained)
  - [Development Journey](#development-journey)
- [About Me](#about-me)
  - [Brief Introduction](#brief-introduction)
  - [Personal Connection](#personal-connection)

## Project Overview

### The Mission

The project was created to visualize how photons behave around a Schwarzschild black hole. The 2D visual shows the exact paths photons take around a black hole, while the 3D visual shows a real-time black hole visualization.

### Executive Summary

This two-part project simulates the paths of photons (light rays) around a non-rotating, uncharged black hole described by the **Schwarzschild solution** to Einstein's field equations.

In the 2D module, photons are launched from the left side of the screen on parallel trajectories. Every curve you see is the result of numerically integrating the actual equations of general relativity.

In the 3D module, each pixel the screen displays to you is a ray-marched (iterative ray-tracing) photon from whichever angle and position the camera is at. The black hole you see at the center of your screen is visually bending the images of stars behind it through gravitational lensing.

All geodesic equations are derived from the **Schwarzschild metric** using the **Euler–Lagrange equation** (and cross-checked with standard results).

### Video Demo

Work in progress.

## Quick Start

### Installation

N/A

### Running the Simulation

N/A

## Scientific Background

### Relativity 101

#### The Core Concept

In Newtonian Physics, gravity is often depicted as a force, but that isn't technically true. In actuality, space and time are the interwoven, flexible "fabric" of the universe (concretely known as spacetime). Bending this fabric is what creates gravity. Imagine spacetime as a trampoline and the sun as a heavy ball. If you place that ball in the center, the weight pulls the woven mat down, and any other ball you toss onto the trampoline eventually falls inward due to the mat's curvature. For a black hole, it's like placing an impossibly dense ball, creating a "bottomless" pit. This actually creates a specific trajectory known as the "geodesic." Geodesics are the "shortest path on a curved surface," and in the context of the universe, that "curved surface" is spacetime. 

#### The Null Geodesic

There are two types of geodesics: the timelike and the null. Timelike geodesics are the paths massive objects follow. For example, a plane needs to fly from New York City, USA, to Madrid, Spain. If you had to draw the line between these two cities on a 2D map, you would probably draw a flat line between the two points, but that isn't actually the shortest path. This is due to the Earth's spherical curvature!

![Comaprison 2D](https://gisgeography.com/wp-content/uploads/2019/07/RhumbLine-GreatCircle-2.jpg "Comparison of the line and a geodesic")

In the image above, you can see the difference in the lines! But if we switch to a 3D view of the Earth, you can see that it's a straight line.

![Geodesic View 3D](https://gisgeography.com/wp-content/uploads/2019/07/Great-Circle-Sphere-1.jpg "Geodesic 3D view")

For light, the same geometric principle applies—but because photons travel at c, their path is a null geodesic. The only difference is that light doesn't experience time as we do. From the photon's perspective (to the extent that concept applies), no time passes at all—it is emitted and absorbed in the same instant.

#### The Point of No Return

The anatomy of a black hole is made up of two main things: an event horizon and a singularity. The singularity is the true "center" of the black hole in which all known physics breaks down. On the other hand, the event horizon is the boundary where gravity becomes so strong that not even light can escape. Anything that crosses that line is doomed to travel inside the black hole.

### Mathematical Framework

**Continue here...**

### Key Phenomena

#### Time Dilation

#### Gravitational Redshift

## Further Reading

### Math and Physics Explained

### Development Journey

## About Me

### Brief Introduction

### Personal Connection
