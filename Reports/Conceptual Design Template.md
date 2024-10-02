# Conceptual Design

This document outlines the objectives of a conceptual design. After reading your conceptual design, the reader should understand:

- The fully formulated problem.
- The fully decomposed conceptual solution.
- Specifications for each of the atomic pieces of the solution.
- Any additional constraints and their origins.
- How the team will accomplish their goals given the available resources.

With these guidelines, each team is expected to create a suitable document to achieve the intended objectives and effectively inform their stakeholders.


## General Requirements for the Document

- All submissions must be composed in Markdown. Please refrain from submitting PDFs or Word documents.
- All sources must be cited unless the information is common knowledge among the writer's audience.
- The document must be written in the third person.
- An introduction must be included.
- The latest fully formulated problem must be clearly stated using "shall" statements.
- The document must include a complete, well-specified high-level solution, including a system block diagram.
- For each atomic subsystem, a functional description, inputs, outputs, and specifications must be provided.
- A statement of ethical, professional, and standards considerations should be included, detailing the specific constraints they have imposed.
- A Gantt chart must be included, detailing all tasks necessary to complete the detailed design and specifying the individual(s) responsible for each task.


## Introduction

The introduction is intended to reintroduce the fully formulated problem. 


## Restating the Fully Formulated Problem

The fully formulated problem is the overall objective and scope complete with the set of shall statements. This was part of the project proposal. However, it may be that the scope has changed. So, state the fully formulated problem in the introduction of the conceptual design and planning document. For each of the constraints, explain the origin of the constraint (customer specification, standards, ethical concern, broader implication concern, etc).

The project **must** include 1 or more constraints (shall statements) originating from each of the following: broader impacts, ethical considerations, and engineering standards. 

## Hi-Level Solution

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

### Block Diagram Expectations

Block diagrams are a great way to provide a big picture understanding of a system and the relationships of the individual components. In general, block diagrams borrow from visual modeling languages like the universal modeling language (UML). Each of the blocks represent sub-systems and each of the connections represent that the two (or more) blocks connected have a relationship. Typically, the relationship in a system diagram is that of input to output. 

Each sub-system should be represented by a single block. For each block in the sub-system there should be a short explanation of the functional expectations for that block and the associated constraints. For each of the connections, there should be a short description of the expectations for that relationship including what is being represented by the relationship (power, analog signal, serial comm, wireless comm, etc) and the constraints. 

The result should be a complete view of a well defined system that delegates all atomic responsibilities necessary to accomplish the project scope to sub-systems and their interactions.






## Atomic Subsystem Specifications

Given the hi-level design, give a detailed description of what function each subsection should perform. This should inculued verabie about how the subsystem helps achinve the projects goals. Also inculde a functional description of operation. Describe the interface of the subsystem to other subsystems this should inculde inputs & outputs to other subsystems. If communication protocal is used document what will be sent and what will be recieved.

For software subsystems draw the expected user interface (if any) and give a functional flow charts that capture the major sequencial steps needed to achive the desired funcsion.

For all subsystmes formulate shall statments. Make the stament detailed enough that an engineer unfamillar with your project could design the subsystem based on your specifiactions (you get to pretend that you are the customer in this case).


## Ethical, Professional, and Standards Considerations

In the project proposal, each team was required to consider what the broader impacts of the project may be to the culture, society, environment, public health, public safety, and economy. They were also required to consider the standards organizations which would inform the design. Here, each team must include a complete discussion regarding how these broader considerations have been used to inform your design (what constraints, specifications, or practices etc. are in place due to the consideration of these and how the constraints address these).









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







## References

All sources used in the project proposal that are not common knowledge must be cited. Multiple references are required.


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. Clearly document each member's contributions to this proposal.

