Pneumatic Limb Controller
-------------------------

$$
\newcommand{\dee}{\mathop{}\!\mathrm{d}}
$$

Strength Capabilities
---------------------

* $P_1$ is the pressure on the near side of the plunger (Newtons per square meter).
* $P_2$ is the pressure on the far side of the plunger (Newtons per square meter).
* $D$ is the bore (diameter) of the pneumatic piston (meters).

The force acting on the piston plunger is $(P_1 - P_2)\pi\left(\frac D 2 \right)^2$.

With $P_1, P_2$ in PSI and $D$ in millimeters, we have $P_1 \mathrm{lbf}/(25.4 \mathrm{mm})^2 \pi\left(\frac {D \mathrm{mm}} 2 \right)^2 \approxeq 0.001217369588005(P_1 - P_2)D^2$.

So if we have 100psi on one end and 0psi on the other of a 32mm bore piston, the force is $0.001217369588005(100 - 0)32^2$, or $124.658645811712$ pounds-force. That means it would be able to lift a 124 pound weight directly upwards.

Of course, the actual force exerted by the limbs is less than this due to limb leverage. For example, the knee joint in the design has a roughly 1:6 mechanical advantage, which means that we would actually be able to lift a 21 pound weight directly upwards.

Pneumatic Controller
--------------------

* $P_1$ is the pressure on the near side of the plunger (Newtons per square meter).
* $P_2$ is the pressure on the far side of the plunger (Newtons per square meter).
* $x$ is the extension of the piston (meters).
* $\theta$ is the rotation of the limb (radians).
* $L$ is the length of the limb (meters).
* $s$ is the distance between the limb and the piston (meters).

We want a function $f(\theta')$ that accepts a target position and results in the amount to set $P_1 - P_2$ to to ensure $\theta$ converges toward $\theta'$ quickly.

Let $k$ be the surface area of the piston plunger. Then $\frac{\dee^2 x}{\dee t^2} = k(P_1 - P_2) + F$.

By the cosine law, $x^2 = s^2 + L^2 - 2sL \cos \theta$ and $x = \sqrt{s^2 + L^2 - 2sL \cos \theta}$.

The accuracy of $\cos$ is $\pm 0.001$ in the output, so $x = \sqrt{s^2 + L^2 - 2sL \cos \theta \pm 0.002sL}$.

The pneumatic controller uses this to convert the setpoint and measured value of a PID controller so that it works in terms of $x$ rather than $\theta$. The PID controller then calculates the value of $P_1 - P_2$.
