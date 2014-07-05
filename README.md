Project Exo
===========
Design, schematics, and building instructions for a powered full-body exoskeleton.

Requires a basic understanding of math, usage of common power tools, and a fair bit of free time to build.

Total parts cost: \$810.48 CAD. ;wip: update this

Current Status
--------------

| Stage                         | Status        | Time Needed (Approximate) |
|:------------------------------|:--------------|:--------------------------|
| Design Research               | **Complete**  | 2 weeks                   |
| Design Requirements           | **Complete**  | 4 days                    |
| Mechanical Design/Prototyping | 40% done      | 4 weeks                   |
| Electronic Design/Prototyping | 10% done      | 5 weeks                   |
| Part/Tool Sourcing            | _Pending_     | 20 days                   |
| Production/Revision           | _Pending_     | 4 weeks                   |

Estimated date of completion is **end of 2014**.

### To-Do:

* Finish design.
* Reduce amount of custom parts.
* Create a parts list.
* Write custom pneumatic piston controller with position and stiffness controls.
* Figure out where to get access to a CNC milling machine + machine shop.

Design
------

* One human operator (designed for height ~1.7m, but adjustable).
* Rigid, free-standing chassis made out of simple plumbing parts and common building materials, designed with large tolerances and excellent safety margins.
* Air tank stores compressed air for driving the pneumatic components.
* Sealed 12V lead-acid battery powers onboard electronics.
* Pressure sensitive armbands and legbands attached to chassis sense operator motion, which is fed into high-level control.
* Arduino driving a Darlington array provides high level control of all other subsystems.
* Electrically controlled 12V pneumatic valves control airflow to the pneumatic pistons.
* Pneumatic pistons move chassis.

Project Exo is designed to be easy to build, powerful, and as failsafe as possible. All parts operate well within their safety ratings, and plenty of care is taken to restrict the range of motion so that the actuators cannot harm the operator if they malfunction.

Files
-----

In order to view all the design files, you will need [Fritzing](http://fritzing.org/home/) and [Blender3D](http://www.blender.org/).

`Design/Design.blend` contains a Blender3D CAD file for the entire system. ;wip: add this to the Git repo
`Design/High Level Controller` contains a Fritzing schematic for the high level pneumatics controller.

Tools
-----

* Metal/plastic saw
* Soldering iron
* Standard epoxy
* Hot glue gun + hot glue
* Screwdriver
* Pliers
* Scissors

A Dremel is also always a nice thing to have on hand. Not strictly necessary, but highly recommended.

Mechanical Parts
----------------

The mechanical parts list can be broken down as follows:

| Part                             | Quantity                  | Market Price (CAD)      |
|:---------------------------------|:--------------------------|------------------------:|
| Pipes and pipe joints/connectors | A lot                     |                   50.00 | ;wip: not an exact value
| Double action pneumatic pistons  | 6 short, 2 small, 4 large | 103.44 + 22.08 + 112.84 |
| Pneumatic regulators             | 3                         |                   52.50 |
| Pneumatic valves                 | 24                        |                  177.60 |
| Air tank                         | 1                         |                   59.99 |
| Battery                          | 1                         |                   27.49 |
| PVC primer + cement              | 500ml                     |                   19.98
| Pneumatic accessories            | 1 compressor, 1 filter    |          137.09 + 19.99 |

In total, the current market price of the mechanical parts is \$783 CAD.

### Pipes and Pipe Joints/Connectors

I will be using 2cm outer diameter PVC piping, but any similar diameter will work - the tolerances are reasonably loose. The diameter should be at least 1.5cm to ensure the frame is strong enough. Use schedule 80 piping if possible - it has thicker pipe walls and is therefore stronger.

The chassis is constructed mostly out of pipes and joints, so the strength of the frame is significantly affected by how strong the pipes and joints are.

Pipes and pipe joints/connectors should be available at almost any [hardware store](http://homehardware.ca/en/rec/index.htm/Plumbing-Electrical/Plumbing/Waterworks/Water-Pipes/Pvc/1-1-4-x-10-PVC-Pressure-Pipe/_/N-2pqfZ67l/Ne-67n/Ntk-All_EN/R-I3262061). Failing that, see [Amazon](http://www.amazon.com/Charlotte-Pipe-PVC-04010-0200/dp/B003OSSDWW/) or similar.

Metal pipes would make the whole frame stronger, but the tools for working with them are harder to obtain.

Pipe joints include things like elbow joints, tee joints, and more obscure ones like vee joints. These are optional if using metal pipes and welding them together.

The design files includes some "unconventional" pipe fittings such as four way and corner fittings, which are generally not available in stores due to not being very useful for plumbing purposes. These fittings can instead be obtained from specialty PVC construction suppliers:

* [Formufit](http://www.formufit.com/), in addition to selling all of the types of PVC components needed for this project, offers guides and tutorials for working with PVC.
    * A little bit more expensive but very good quality.
    * The products are also sold on [Amazon](http://www.amazon.com/gp/aag/main?ie=UTF8marketplaceID=ATVPDKIKX0DER&seller=A1T0WSE1JGO9PT).
* [PVC Plans](http://www.pvcplans.com/pvc-suppliers.htm) maintains a list of suppliers, many of which offer these non-standard fittings.
    * USA-centric, but several will ship internationally. Sellers seem reputable.
* [PVC Fittings](http://pvcfittings.com/) offers the lowest prices 
    * Ridiculously large variety of parts available, but shipping options are limited.

### Double Action Pneumatic Pistons

I will be using [MAL 16 X 175 Double Action Pneumatic Pistons](http://www.ebay.com/itm/1Pcs-Single-Rod-16-x-175-Dual-Action-Mini-Pneumatic-Cylinder-/141094409413) (16mm bore, 175mm stroke) as the small pistons.

I will be using [MAL 32 X 175 Double Action Pneumatic Pistons](http://www.ebay.com/itm/32mm-Bore-175mm-Stroke-Double-Action-Aluminum-Alloy-Pneumatic-Air-Cylinder-/310973376044) (32mm bore, 175mm stroke) as the large pistons.

;wip: almost out of stock, maybe http://www.ebay.com/itm/MA32-175S-CM-Mini-Pneumatic-Cylinder-Double-Acting-32-175mm-AIRTAC-Type-/261362580432 or http://www.ebay.com/itm/AIRTAC-Type-MA32-175S-CM-Mini-Pneumatic-Cylinder-Double-Acting-32-175mm-/171175049747 instead

I will be using [CQ2B32-100D Double Action Pneumatic Pistons](http://www.ebay.com/itm/General-Model-CQ2B32-100D-Compact-Cylinder-Double-Acting-32-100mm-/360898853102) (32mm bore, 100mm stroke) as the short pistons.

The exact bore and stroke length isn't that important as long as it outputs enough force and still fits inside the frame.

The pistons are responsible for actually moving the frame, and the operator inside of it, around.

The bore is the diameter of the hole in which the plunger can move back and forth.

It is very important that the pistons are double action. This means that they can push out and pull in - single action cylinders can only do one of these.

The amount of force the piston can output is (essentially) proportional to the surface area of the plunger head, so $F = 0.006895 \pi \frac{d^2}{4} p$, where $F$ is the force in Newtons (9.8 Newtons is roughly 1kg in Earth gravity), $d$ is the bore diameter in mm, and $p$ is the pressure in psi.

So to be able to lift 10kg with a pressure of 100psi, we have $9.8 \times 10kg = 0.006895 \pi d^2 100$, so $d = \sqrt{\frac{9.8 \times 10}{0.006895 \frac 1 4 \pi 100}} \approxeq 13.5$. So we need a bore of at least around 14mm to do the lifting.

The stroke length is very important as well. This is the length that the piston can extend from rest position - the length of the path the piston can extend along. If the stroke is not long enough, the range of motion of some of the joints may be restricted. If the stroke is too long, it is possible to bend the joints too far, which could be a safety concern if there is a malfunction.

### Pneumatic Regulators

I will be using [4214-ADJ 1/4" Male-to-Female Pressure Regulators](http://www.amazon.com/Coilhose-Pneumatics-4214-ADJ-Adjustable-Regulator/dp/B0037QFFT0/), which are rated for 150psi max input pressure and output between 50psi and 145psi.

;wip: possibly http://www.amazon.com/Mini-Pressure-Regulator-Free-Gauge/dp/B004VGA7NY/ instead, it's cheaper

Pneumatic regulators are very important for safety purposes - they output gas at a constant pressure, even if the input pressure goes over.

### Pneumatic Valves

I will be using [1/2" Normally Closed 12V Solenoid Air Valves](http://www.ebay.com/itm/Electric-Solenoid-Valve-For-Water-Air-N-C-12V-DC-1-2-Normally-Closed-/370725933898), which are normally closed and rated at 116psi and continuous duty. When activated, they draw about 250mA.

Pneumatic air valves control airflows using electrical signals. This allows us to control the pneumatic actuators from the electrical systems.

### Air Tank

I will be using a [DSBP99210-2 2 gallon air tank](http://www.amazon.com/Smittybilt-99210-2-Gloss-Gallon-Fittings/dp/B003EP2XA8/) rated for 150psi.

The air tank stores the compressed air that drives the pneumatic actuators.

### Battery

I will be using a [UT1270 12V Sealed Lead-Acid Battery](http://www.amazon.ca/UltraTech-UT1270-Sealed-Battery-UT-1270/dp/B00BMUV2VS/), which is rated at 7Ah. It is also worth getting a [12V battery charger](http://www.amazon.com/gp/product/B004EI6A8K/) to go with it.

For testing purposes, it might also be useful to have a [12V Wall Power Supply](http://www.amazon.ca/Quality-Supply-Adapter-Converter-100-240V/dp/B00HSW3X3O/) for testing purposes.

### PVC Primer + Cement

I will be using [Oatley 30755 PVC Primer/Cleaner](http://www.amazon.ca/Oatey-30755-Purple-Primer-Fittings/dp/B00002N6NV/) and [Oatley 30883 PVC Cement](http://www.amazon.ca/Oatey-30883-Medium-Cement-Misc/dp/B000KGB2MO/) for PVC joining.

PVC cement joins PVC by reacting with the two surfaces to join and chemically bonding them together. Out of the factory, PVC is coated with various other material, which must be removed using PVC primer.

The resulting bond has high structural strength, and the joined piece can be load bearing.

### Pneumatic Accessories

An air compressor is very useful for refilling the air tank. I will be using a [VIAIR 300P Portable Air Compressor](http://www.amazon.ca/VIAIR-30033-300P-Portable-Compressor/dp/B000X90YUO/), which is rated for 150psi max.

;wip: also consider http://www.amazon.com/VIAIR-150-PSI-High-Flow-Source/dp/B000X9LTXA/ to replace the compressor and air tank

An air filter helps remove moisture and dust, in order to keep the system clean over extended use. I will be using a [F1401 1/4" 40 Micron Air Filter](http://www.amazon.com/Primefit-F1401-Filter-60-SCFM-100-PSI/dp/B00IDCYIPK/), which are rated for 145psi max.

Electronic Parts
----------------

The electronic parts list can be broken down as follows:

| Part                             | Quantity                  | Market Price (CAD)      | Vendor                                                                               |
|:---------------------------------|:--------------------------|------------------------:|:-------------------------------------------------------------------------------------|
| P120PK potentiometer             | 12                        |                    9.48 | [Digi-Key](http://www.digikey.ca/product-search/en?keywords=P120PK)                  |
| Arduino Nano revision 3          | 1                         |                   18.00 | [Amazon](http://www.amazon.ca/SainSmart-Nano-v3-0-Compatible-Arduino/dp/B00761NDHI/) |
| 4-channel 1.5A Darlington array  | 6                         |                   18.12 | [Digi-Key](http://www.digikey.ca/product-detail/en/ULN2069B/497-2352-5-ND/599589)    |
;wip: pressure switches, perfboard, etc.

In total, the current market price of the mechanical parts is \$27.48 CAD. ;wip: update this

Electronic parts are a bit more fickle than the mechanical ones, since there are so many factors to consider that suggesting substitutes and alternatives would be impractical. I will be using the exact parts specified.

Building
--------

DISCLAIMER: Compressed air, electricity, and power tools can be dangerous if you're not careful. I am not responsible for any death, dismemberment, spontaneous defecation, or hair loss that may result from following the instructions in this document.

;wip

License
-------

<a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/"><img alt="Creative Commons License" style="border-width:0" src="http://i.creativecommons.org/l/by-nc-sa/4.0/88x31.png" /></a><br /><span xmlns:dct="http://purl.org/dc/terms/" property="dct:title">Project Exo</span> by <a xmlns:cc="http://creativecommons.org/ns#" href="https://github.com/Uberi/ProjectExo" property="cc:attributionName" rel="cc:attributionURL">Anthony Zhang</a> is licensed under a <a rel="license" href="http://creativecommons.org/licenses/by-nc-sa/4.0/">Creative Commons Attribution-NonCommercial-ShareAlike 4.0 International License</a>.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
