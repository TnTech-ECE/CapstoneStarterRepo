# Project Proposal

This document provides a comprehensive explanation of what a project proposal should encompass. The content here is detailed and is intended to highlight the guiding principles rather than merely listing expectations. The sections that follow contain all the necessary information to understand the requirements for creating a project proposal.


## General Requirements for the Document
- All submissions must be composed in markdown format.
- All sources must be cited unless the information is common knowledge for the target audience.
- The document must be written in third person.
- The document must identify all stakeholders including the instuctor, supervisor, and cusotmer.
- The problem must be clearly defined using "shall" statements.
- Existing solutions or technologies that enable novel solutions must be identified.
- Success criteria must be explicitly stated.
- An estimate of required skills, costs, and time to implement the solution must be provided.
- The document must explain how the customer will benefit from the solution.
- Broader implications, including ethical considerations and responsibilities as engineers, must be explored.
- A list of references must be included.
- A statement detailing the contributions of each team member must be provided.


## Introduction

The introduction must be the opening section of the proposal. It acts as the "elevator pitch" of the project, briefly introducing the objective, its importance, and the proposed solution. Because readers may only read this section, it should effectively capture their attention and encourage them to read further.

Toward the end of the introduction, include a subsection that outlines what the proposal will cover. This helps set reader expectations for the ensuing sections.


## Formulating the Problem

Formulating the problem or objective involves clearly defining it through background information, specifications, and constraints. Think of it as "fencing in" the objective to make it unambiguously clear what is and is not being addressed and why.

Questions to consider:
- Who does the problem affect (i.e. who is your customer)?
- Why do we need this solution?
- What challenges necessitate a dedicated, multi-person engineering team?
- Why aren’t off-the-shelf solutions sufficient?

### Background

Provide context and details necessary to define the problem clearly and delineate its boundaries.

### Specifications and Constraints

Specifications and constraints define the system's requirements. They can be positive (do this) or negative (don't do that). They can be mandatory (shall or must) or optional (may). They can cover performance, accuracy, interfaces, or limitations. Regardless of their origin, they must be unambiguous and impose measurable requirements.

#### Specifications

Specifications are requirements imposed by **stakeholders** to meet their needs. If a specification seems unattainable, it is necessary to discuss and negotiate with the stakeholders.

#### Constraints

Constraints often stem from governing bodies, standards organizations, and broader considerations beyond the requirements set by stakeholders.

Questions to consider:
- Do governing bodies regulate the solution in any way?
- Are there industrial standards that need to be considered and followed?
- What impact will the engineering, manufacturing, or final product have on public health, safety, and welfare?
- Are there global, cultural, social, environmental, or economic factors that must be considered?


## Survey of Existing Solutions

Existing solutions for automated chessboards range from DIY projects to commercially-produced boards:

* **DIY Solutions**: Several open-source projects present designs of varying complexity. Some rely on stepper motors and Arduinos for piece movement, while others incorporate Raspberry Pis and computer vision to track pieces and issue precise directions via microcontrollers.
* **Industrial Solutions**: Several companies offer high-end automated boards with AI opponents and online connectivity. These solutions, however, are often too expensive for the average user, making them impractical for this application.

Below are multiple current solutions, complete with lists of reasons as to why any particular solution would not work for solving this problem.

*ChessUp 2 Smart Chess Board [1]: A WiFi-enabled smart chessboard featuring chip recognition technology and direct integration with Chess.com, offered at a relatively lower cost of $399.99.

Cons:
* Cannot move pieces autonomously.
* Requires a stable WiFi connection to Chess.com for AI functionality.

*Miko Chess Grand [2]: A premium wooden smart chessboard equipped with a magnetic robotic arm beneath the surface for automated piece movement. It includes wooden pieces, a high-quality 12-pound wooden board, and dedicated storage space for captured pieces, priced at $549.99.

Cons:
* The board’s weight makes it less portable.
* High-quality materials increase overall cost.
* The robotic arm cannot make moves for the first player except when removing pieces from the board.
* Does not include voice recognition functionality.

*Chessnut Move [3]: An advanced robotic chessboard featuring integrated voice command support, offline AI gameplay, and connectivity with Chess.com. Priced at $899.99, it provides one of the most interactive experiences currently available.

Cons:
* Pieces occasionally collide during automated movement.
* The design relies on each piece containing its own robotic base, which significantly increases cost.
* Oversized piece bases reduce aesthetic appeal and make the board feel crowded.

*GoChess Mini [4]: A compact and lightweight smart chessboard featuring illuminated path indicators for piece movement, Bluetooth connectivity, adjustable AI difficulty, and Chess.com integration. Priced at $249.95 and weighing 6.6 pounds, it offers an affordable entry point into smart chessboards.

Cons:
* Battery-powered system requires two hours to fully charge, supporting up to 100 hours of playtime (reduced to about five hours when lights are enabled).
* Does not support automated piece movement, requiring players to manually move all pieces.
* Lacks an automated reset function for returning pieces to their starting positions.

*8x8 Smart Chess Board [5]: A Raspberry Pi–controlled prototype that uses stepper motors, lead screw mechanisms, and an electromagnetic head to move magnetized chess pieces. The design mimics the motion of a 3D printer to achieve movement across the XY plane.

Cons:
* The stepper motor system has experienced notable failures.
* The bill of materials (BOM) is incomplete.

*Techievince 8.0 – Electronics Club IITG Project [6]: An Arduino-based system programmed in Embedded C that integrates the Micro Max chess engine using Minimax and Alpha-Beta algorithms. It employs an XY trolley system with stepper motors, magnetized pieces, and an electromagnetic head, along with multiplexed reed switch sensors for piece displacement detection.

Cons:
* Visually less appealing compared to other designs.
* Requires specialized magnetic chess pieces, increasing overall cost.
* Does not include voice recognition functionality.

*Chess Automation Using Computer Vision [7]: A computer vision–driven approach that uses a camera, OpenCV, and NumPy to detect the chessboard, track pieces in real time, and record game history. The system identifies moves directly from image or video input without requiring embedded magnets or sensors.

Cons:
* Lacks integrated AI functionality.
* Cannot move pieces autonomously.
* Lacks an automated reset function for returning pieces to their starting positions.







Despite the availability of existing smart chessboard solutions, challenges such as high cost, limited offline functionality, lack of voice recognition, and frequent piece collisions remain key barriers for the average user. The development of a new system should prioritize affordability, lightweight design, seamless voice integration, and reliable automated piece movement with full reset functionality for both players.

This project aims to bridge the gap between current offerings by delivering a cost-effective, user-friendly, and offline-capable automated chessboard that eliminates common frustrations while enhancing accessibility for everyday players.

## Measures of Success

Define how the project’s success will be measured. This involves explaining the experiments and methodologies to verify that the system meets its specifications and constraints.


## Resources

Each project proposal must include a comprehensive description of the necessary resources.

### Budget

Provide a budget proposal with justifications for expenses such as software, equipment, components, testing machinery, and prototyping costs. This should be an estimate, not a detailed bill of materials.

### Personel

Identify the skills present in the team and compare them to those required to complete the project. Address any skill gaps with a plan to acquire the necessary knowledge.

Besides the team, also state who you choose to be you supervisor and why.

State who your instrucotr is and what role you expect them to play in the project.

### Timeline

Provide a detailed timeline, including all major deadlines and tasks. This should be illustrated with a professional Gantt chart.


## Specific Implications

Explain the implications of solving the problem for the customer. After reading this section, the reader should understand the tangible benefits and the worthiness of the proposed work.


## Broader Implications, Ethics, and Responsibility as Engineers

Consider the project’s broader impacts in global, economic, environmental, and societal contexts. Identify potential negative impacts and propose mitigation strategies. Detail the ethical considerations and responsibilities each team member bears as an engineer.


## References

[1] ChessUp 2 Smart Chess Board. Bryght Labs. (n.d.). https://playchessup.com/products/chessup-2

[2] Miko Chess Grand. Miko. (n.d.). https://miko.ai/pages/miko-chess-grand 

[3] Chessnutech. (n.d.). Chessnut move - advanced robotic chessboard with Plastic Pieces. Chessnut. https://www.chessnutech.com/products/chessnut-move-advanced-robotic-chessboard-with-plastic-pieces 

[4] GoChess Mini. Particula. (n.d.). https://particula-tech.com/products/gochess-mini?variant=45806634402040&country=US&currency=USD&utm_medium=product_sync&utm_source=google&utm_content=sag_organic&utm_campaign=sag_organic&srsltid=AfmBOooAY445sOW--M7GA0T4jbNkHE609yl_YKlFLR9iyhF7eX9KFsd9ubc

[5] MFOSSociety. (n.d.). MFOSSociety/8-8: 8/8: Smart Chess Board: An Automated Ai Chess Board. GitHub. https://github.com/MFOSSociety/8-8 

[6] sumit11899. (n.d.). SUMIT11899/automated-chessboard. GitHub. https://github.com/sumit11899/Automated-ChessBoard 

[7] Simarmehta. (n.d.). Simarmehta/CHESSAUTOMATION_CV. GitHub. https://github.com/simarmehta/chessAutomation_CV 


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. In this section, each team member is required to document their individual contributions to the report. One team member may not record another member's contributions on their behalf. By submitting, the team certifies that each member's statement of contributions is accurate.
