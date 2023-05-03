## This Document - Conceptual Design and Planning Documentation Specifications

This document should not be thought of as an outline. Rather, this document explains the goal and specific things that the reader should understand. Armed with these expectations, each team is expected to design an appropriate document to accomplish the goal and appropriately educate their stakeholders. 


### Big Picture Goal of the document

The goal of the conceptual design and planning document is to leave the reader understanding the (1) fully formulated problem, (2) fully decomposed conceptual solution, (3) the constraints and where they arise from, (4) how the constraints will be analytically (not experimentally) validated, and (5) a detail design schedule (with an explanation of why it is optimal). 

The above is NOT an outline. It is the goal of the document. Consider all the requirements given herein and devise an outline that will accomplish the requirements.


### Conceptual Design and Design Planning Objectives

The general purpose of conceptual design and planning is to identify a concept and process that will:

1. Conform to all constraints
2. Maximize attainment of stakeholder goals
3. Minimize sources of risk
	1. critical unknowns
	2. delivery problems
4. Minimize consumption of resources
5. Optimize the Timeline for the Detail Design
	1. Address critical unknowns early
	2. If system $A$ places a constraint on system $B$, *in general* system $A$ should be designed first


### General requirements for the document

1. Must conform to the latest IEEE conference format.
2. All sources must be cited using IEEE inline citations unless the information is common knowledge among the writer's audience.
3. Must be in third person.
4. Must contain an introduction.
5. Must state the up to date fully formulated problem (shall statements) in a sub-section of the introduction.
6. Must contain an explanation of how conceptual design fits into the larger process of engineering design.
7. Must contain a statement of ethical, professional, and standards considerations and the specific constraints they have imposed.
8. Must contain a complete, well specified system block diagram for the team's solution to the problem.
9. For each sub-system (block in the diagram), the complete inputs, outputs, and constraints must be given with their origin (what caused the constraint).
10. For each sub-system, the analytical method(s) which will be used to validate compliance to the constraint(s) must be stated.
11. Must contain a gantt chart detailing **all** tasks that will be necessary to complete the detail design and analytical verification and by whom the tasks will be completed. (this includes any skill acquisition that will be necessary)


### Introduction

In this case, the goal of the introduction section is not to persuade. Rather, in a design document, the introduction is intended to reintroduce the fully formulated problem. 

#### Restating the Fully Formulated Problem

The fully formulated problem is the overall objective and scope complete with the set of shall statements. This was part of the project proposal. However, it may be that the scope has changed. So, state the fully formulated problem in the introduction of the conceptual design and planning document. For each of the constraints, explain the origin of the constraint (customer specification, standards, ethical concern, broader implication concern, etc). The project **must** include 1 or more constraints (shall statements) originating from each of the following: broader impacts, ethical considerations, and engineering standards. 


### Background

Background information may be needed. If significant background information must be introduced to explain anything about the solution, it should be housed in the background section. 


### Ethical, Professional, and Standards Considerations

In the project proposal, each team was required to consider what the broader impacts of the project may be to the culture, society, environment, public health, public safety, and economy. They were also required to consider the standards organizations which would inform the design. Here, each team must include a complete discussion regarding how these broader considerations have been used to inform your design (what constraints, specifications, or practices etc. are in place due to the consideration of these and how the constraints address these).


### Expectations for the Draft

The draft should show very significant progress toward completion of the design phase 1 document. There must be a complete outline in place with more than 60% of the document complete. The complete system block diagram for the conceptual solution must be in place with all constraints detailed for the sub-systems. 


### Block Diagram Expectations

Block diagrams are a great way to provide a big picture understanding of a system and the relationships of the individual components. In general, block diagrams borrow from visual modeling languages like the universal modeling language (UML). Each of the blocks represent sub-systems and each of the connections represent that the two (or more) blocks connected have a relationship. Typically, the relationship in a system diagram is that of input to output. 

Each sub-system should be represented by a single block. For each block in the sub-system there should be a short explanation of the functional expectations for that block and the associated constraints. For each of the connections, there should be a short description of the expectations for that relationship including what is being represented by the relationship (power, analog signal, serial comm, wireless comm, etc) and the constraints. 

The result should be a complete view of a well defined system that delegates all atomic responsibilities necessary to accomplish the project scope to sub-systems and their interactions.



### Example conceptual design documentation for an atomic subsystem

##### About the example
In conceptual design, the goal is to decompose the objective into individual, atomic pieces. The sum of which will accomplish the overarching goal and meet all constraints. During conceptual design, do not attempt to identify **how** to do something, but rather be very specific about **what** will be done. Each block in the diagram will represent a subsystem that performs a specific task (a **what**). 

##### The example
Subsystem A in the block diagram (not shown) is a system to measure the ambient temperature (input is temperature between 109 to 167 C) inside the toaster and communicate the temperature (output is encoded temperature with at least 2.2 degree C accuracy and 0.5 degrees of precision) to the temperature control system. 

Description of subsystem and interface constraints:
The input range constraint arises from the fact that anything below 110C would not initiate the Maillard reaction necessary to begin toasting bread (1,3). 167 is above the maximum temperature for carmelization in bread (2). So, toasting must happen whithin this range of temperatures and measuring temperatures outside this range is out of scope. 

Justification:
The precision of the encoding of the output comes from "shall have 10 toasting levels". Given 10 levels which are spread across the temp range 110 to 166 C, each level occupies 5.6 degrees. Encoding the temperature in steps of at least .5 degrees C will guarantee that each level has at least 10 corresponding temperature steps. Further, the uncertainty based on the accuracy is 2.2 degrees C. Thus, if the median temperature step is held between the levels this results in target tempt + 2.8 degrees (the median step) +- 2.2 degrees (the accuracy in a k type thermocouple) +- 0.5 degrees (precision), the possible real temp is guaranteed to be between target temp + 5.5 (in the target range) and target temp + 0.1 (in the target range).

The communication protocol between subsystem A and the temperature control system is undefined and the speed of communication is undefined. These will be determined during detail design as these are determined by **how** we choose to implement these systems. 

Analytical Verification:
To analytically verify the constraints are met, a model of the system using the datasheets of components selected and the designed electrical circuitry will be made. The input to the model will be swept from 110C to 166C at steps of 0.25 degrees celcius and the output of the model at each step will be recorded in an excel table. If the encoded output is within 2.2 degrees C +- 0.5 C of the input then the model suggests that the system will meet the requirements.

##### A few notes about the example

Notice that all constraints for the relevant subsystem are discussed, and the origin of each constraint is given with appropriate citation. Notice that a method of analytical verification is given. Finally, notice that the sections for this subsystem are clearly marked. These meet item 3 and 4 from the general document expectations above. 


### Rubric

Was the document written without grammatical errors? (-1 per or -5 max) (TA)

Was first person perspective used where not appropriate? (-1 per or -5 max) (TA) 

Was the document submitted late? (-4 per week) (TA) 

Unprofessional communication. This does not include errors. This does include things that lack appropriate effort or care. (up to -3 per as appropriate) (TA, coordinator, supervisor)

Was a document submitted? (TA)

Was the document submitted in IEEE format? (TA)

Was the document submitted as a pdf? (TA) 

Is there an introduction that reintroduces the fully formulated problem? (supervisor)

Is it clearly explained how this document fits into engineering design (I want to see that the students demonstrate some understanding of the engineering design process)? (coordinator)

Are ethical considerations discussed (evaluate if students demonstrate an ability to factor ethical considerations into engineering design considerations)? (coordinator)

Are standards addressed sufficiently (supervisor)

Is the conceptual solution explained in detail with all constraints? (supervisor)

Is the origin for each constraint given? (TA)

Is there at least one constraint arrising from ethics, broader impacts, and standards each? (TA)

Is there an analytical method given for the validation of each constraint? (TA)

Is there a block diagram representing the complete conceptual solution? (supervisor)

Is the block diagram well specified? (every block and every line between blocks has associated expectations that are stated clearly and concisely and explained in the document) (supervisor)

Are the next steps clearly explained (this may be via the gantt chart)? (TA)

Does the gantt chart map logically from the conceptual design? (supervisor)

Are all sources cited appropriately? (TA)


## Sources

1. Maillard, Louis Camille. "Action des acides amines sur les sucres: formation des melanoidines par voie methodique." CR Acad Sci 154 (1912): 66-68.

2. https://www.scienceofcooking.com/caramelization.htm

3. https://www.scienceofcooking.com/maillard_reaction.htm
