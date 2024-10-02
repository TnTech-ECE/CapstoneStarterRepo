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


## High-Level Solution

Create a big picture solution that will satisfy specification and constrains while minimizing the costs. Identify a concept and process that will:

1. Maximize attainment of stakeholder goals
2. Conform to all constraints
3. Minimize sources of risk
5. Minimize consumption of resources


## Block Diagram

Block diagrams are a great way to provide a big picture understanding of a system and the relationships of the individual components. In general, block diagrams borrow from visual modeling languages like the universal modeling language (UML). Each of the blocks represent sub-systems and each of the connections represent that the two (or more) blocks connected have a relationship. Typically, the relationship in a system diagram is that of input to output. 

Each sub-system should be represented by a single block. For each block in the sub-system there should be a short explanation of the functional expectations for that block and the associated constraints. For each of the connections, there should be a short description of the expectations for that relationship including what is being represented by the relationship (power, analog signal, serial comm, wireless comm, etc) and the constraints. 

The result should be a complete view of a well defined system that delegates all atomic responsibilities necessary to accomplish the project scope to subsystems and their interactions.


## Atomic Subsystem Specifications

Given the high-level design, give a detailed description of what function each subsection should perform. This should inculued a description of how subsystem helps achinve the projects goals. Also inculde a functional description of operation. Describe the interface of the subsystem to other subsystems this should inculde inputs & outputs to other subsystems. If communication protocal is used document what will be sent and what will be recieved.

For software subsystems draw the expected user interface (if any) and give a functional flow charts that capture the major sequencial steps needed to achive the desired funcsion.

For all subsystmes formulate shall statments. Make the stament detailed enough that an engineer unfamillar with your project could design the subsystem based on your specifiactions (you get to pretend that you are the customer in this case).


## Ethical, Professional, and Standards Considerations

In the project proposal, each team was required to consider what the broader impacts of the project may be to the culture, society, environment, public health, public safety, and economy. They were also required to consider the standards organizations which would inform the design. Here, each team must include a complete discussion regarding how these broader considerations have been used to inform your design (what constraints, specifications, or practices etc. are in place due to the consideration of these and how the constraints address these).


## Resources

You have already estimated the resources need to complete a solution. Now refine estimates.

### Budget

Provide a budget proposal with justifications for expenses for each subsystem. Note that his buject proposal could make a greate specification for the sub system. Take the bujects for each subssytems and combine them to forma budget for the whole solution.

### Skills

Identify the skills present in the team and compare them to those required to complete each subsystem. Assign each member to oversee the creation of each subsystem. If you do not have as many subsystems as team members consider breaking your solution down futher to allow everyone the opertunity to manage a subsystem.

### Timeline

Update the detailed timeline (Gantt chart) you created in the project proposal. Make sure to optimize the Timeline for the detail design. Address critical unknowns early and consider if a prototype needs to constructed before the final build to prove out a subsystem. Also if system $A$ places a constraint on system $B$, *in general* system $A$ should be designed first


## References

All sources used in the conceptual desing that are not common knowledge must be cited. Multiple references are required.


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. Clearly document each member's contributions to this proposal.

