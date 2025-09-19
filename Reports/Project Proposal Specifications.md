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

As chess continues to grow in popularity, the demand for new, more interesting chess technology has become increasingly apparent. One of the newest innovations made to meet this demand is the automated chess board. Automated chess boards are capable of moving each piece around the board without human intervention, allowing users to play over the board against computers, people with disabilities, and friends across the world. Although this advancement has provided many new and exciting opportunities in the world of chess, automated boards prove to be too expensive for widespread use by average consumers. This project aims to design an automated chess board at a cheaper price, providing its benefits to more people around the world.

#TODO: HELP!!!

By allowing the autonomous movement of pieces upon receiving a spoken command at a cheaper price, this product will allow a larger audience to enjoy the experience and impact of automated chess boards.


The introduction must be the opening section of the proposal. It acts as the "elevator pitch" of the project, briefly introducing the objective, its importance, and the proposed solution. Because readers may only read this section, it should effectively capture their attention and encourage them to read further.

Toward the end of the introduction, include a subsection that outlines what the proposal will cover. This helps set reader expectations for the ensuing sections.


## Formulating the Problem

Current automated chess boards are expensive and lack features such as online functionality, voice recognition, and unobstructed movement. The goal of this implementation is to improve these features, reduce cost, use accessible parts for easy hobbyist replication, and to make the game more accessible for players with disabilities. Beyond individual use, this new technology could attract new customers to businesses related to board games or leisure locations through its novelty and fascination. Challenges of this project include digital signal processing for voice controls, artificial intelligence (AI) implementation for solo-play, and automating piece movement. 

### Background

During the pandemic, chess increased in popularity [5]. Online chess specifically had a major influx of activity, with Chess.com adding 1 million accounts from March to November 2020, and a 2.8 million member increase in November alone [5]. This newfound popularity opens up opportunities for innovation on this classic game. An automated chess board would support primarily online chess players who want to improve their over-the-board (OTB) game.

AI has had a major impact in the world of chess, especially in the context of online play [6]. It provides learning opportunities, as certain AI can beat any human player. Chess games played OTB do not usually have this capability except for automated boards. AI in OTB implementations will allow players to improve by progressively increasing the strength of their opponent. This function would aid online players transitioning to OTB play, as they could play against AI before a human opponent. This feature also supports those who want to play OTB chess but cannot do so alone.

Many efforts have been made to ensure that chess tournaments are accommodating to those with disabilities [7]. These accommodations still could be improved upon for player autonomy and ease in preparing. For those with Alzheimer’s, other dementias, dyslexia, dysgraphia, fine/gross motor needs, who are blind, or those with a temporary disability such as a broken hand, an accommodation that can be made is the assignment of a Game Assistant (GA) [7]. In cases such as these, the GA may be needed for piece movement, clock pressing, and/or scoring [7]. An automated board could help as an alternative to a GA by helping with piece movement, automatically keeping time, and automating scoring. This would allow players more independence, as they would not have to rely on the assistance of a GA, and fewer volunteers would be needed for tournaments.

<!-- can maybe talk about what the chess club or the table wants in paragraph below if we get them as a customer -->
In recent years, the rise of board game cafés has demonstrated the strong appeal of face-to-face interaction and social gaming [8]. An automated chessboard with a visually engaging design could build on this trend by drawing curiosity and encouraging participation. Its novelty and interactive features would provide a memorable experience for customers, enhancing the atmosphere of businesses and leisure spaces that adopt the technology.

One of the major ways a technology can become widespread is through low cost and easy manufacturability. The current automated chess boards available on the market are often prohibitively expensive for the average consumer [1][2][3][4]. By focusing on affordability and providing open documentation, this project lowers barriers for hobbyists and educators who wish to replicate or modify the design. Reduced costs also make it possible to introduce the technology to a wider audience, including students and lifelong learners, while still preserving the appeal of a physical, interactive product.


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

* **Industrial Solutions**: Several companies offer high-end automated boards with AI opponents and online connectivity. These solutions, however, are often too expensive for the average user, making them impractical for this application.
* **DIY Solutions**: Several open-source projects present designs of varying complexity. Some rely on stepper motors and Arduinos for piece movement, while others incorporate Raspberry Pis and computer vision to track pieces and issue precise directions via microcontrollers.

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

*8x8 Smart Chess Board [9]: A Raspberry Pi–controlled prototype that uses stepper motors, lead screw mechanisms, and an electromagnetic head to move magnetized chess pieces. The design mimics the motion of a 3D printer to achieve movement across the XY plane. The design utilizes a min-max algorithm to generate the best move predictions.

Cons:
* The stepper motor system has experienced notable failures.
* The bill of materials (BOM) is incomplete.

*Techievince 8.0 – Electronics Club IITG Project [10]: An Arduino-based system programmed in Embedded C that integrates the Micro Max chess engine using Minimax and Alpha-Beta algorithms. It employs an XY trolley system with stepper motors, magnetized pieces, and an electromagnetic head, along with multiplexed reed switch sensors for piece displacement detection.

Cons:
* Visually less appealing compared to other designs.
* Requires specialized magnetic chess pieces, increasing overall cost.
* Does not include voice recognition functionality.

*Chess Automation Using Computer Vision [11]: A computer vision–driven approach that uses a camera, OpenCV, and NumPy to detect the chessboard, track pieces in real time, and record game history. The system identifies moves directly from image or video input without requiring embedded magnets or sensors.

Cons:
* Lacks integrated AI functionality.
* Cannot move pieces autonomously.
* Lacks an automated reset function for returning pieces to their starting positions.


Despite the availability of existing smart chessboard solutions, challenges such as high cost, limited offline functionality, lack of voice recognition, and frequent piece collisions remain key barriers for the average user. The development of a new system should prioritize affordability, lightweight design, seamless voice integration, and reliable automated piece movement with full reset functionality for both players.

This project aims to bridge the gap between current offerings by delivering a cost-effective, user-friendly, and offline-capable automated chessboard that eliminates common frustrations while enhancing accessibility for everyday players.

## Measures of Success

Define how the project’s success will be measured. This involves explaining the experiments and methodologies to verify that the system meets its specifications and constraints.

**1. Input Consistency and Reliability**
**Objective**: Verify that voice commands are consistently recognized across varying conditions and accurately synchronized with expected chessboard inputs.
**Methodology**:

* Volume Variation: Conduct recognition trials at different decibel levels and distances from the microphone to ensure consistent accuracy.
* Speaker Variability: Evaluate system performance in regard to varying players with different tones, accents, and pronunciations.
* Command Completion: Verify that the system consistently processes entire commands before producing an output, ensuring no premature or truncated recognition.
* Integration Validation: Confirm that correctly recognized commands result in accurate and legal piece movements on the automated chessboard.

**2. Mechanical Accuracy and Responsiveness**
**Objective**: Verify that chess pieces move accurately, reliably, and within acceptable response times in accordance with input commands.
**Methodology**:

* Movement Consistency: Conduct repeated trials across multiple games to confirm that piece movements occur in a uniform manner and within predictable timeframes.
* Localization Accuracy: Verify that pieces consistently align to the center of their designated destination squares after each move.
* Stability Evaluation: Ensure that pieces remain upright throughout movement and are not displaced or knocked over by adjacent moving pieces.
* Response Time Measurement: Record the interval between input recognition and movement initiation to confirm timely execution.
* Captured Piece Handling: Verify that captured pieces are consistently removed from play and stored without interfering with ongoing gameplay.
* Board Reset Testing: Ensure that the system reliably returns to the initial configuration within a defined time limit.

**3. Portability and Ergonomic Design**
**Objective**: Ensure that the chessboard is lightweight, easy to transport, and designed with a form factor that supports comfortable play without hindrance in various environments.
**Methodology**:

* Weight Benchmarking: Measure total system weight and verify that it remains within the team’s portability threshold for single-person transport.
* Form Factor Assessment: Evaluate board dimensions and height to confirm they do not interfere with gameplay or piece movement.
* User Testing: Conduct trials with target users to gather feedback on size, shape, and portability in public settings.
* Transport Simulation: Test relocation scenarios (e.g., carrying, packing, setup/teardown) to ensure ease of handling and minimal risk of damage.

**4. Power Efficiency and Safety**
**Objective**: Verify that the chessboard operates for extended periods with minimal power consumption, maintains safe operating conditions, and uses a power connection that is practical and safe in typical play environments.
**Methodology**:

* Low-Power Evaluation: Assess the effectiveness of energy-saving modes or optimizations in reducing overall consumption.
* Thermal Safety: Monitor operating temperatures under normal and extended use to confirm the system does not overheat or damage surfaces.
* Electrical Safety Verification: Ensure that power circuitry does not overload the supply or pose risks of short-circuiting.
* Power Supply Assessment: Confirm that the power connection is safe, unobtrusive, and appropriate for public and home settings (e.g., no excessive cord length or tripping hazards).




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

[5] R. Lahood, "The Queen’s Gambit, the Chess Boom, and the Future of Chess," Michigan Journal of Economics, Apr. 5, 2021. https://sites.lsa.umich.edu/mje/2021/04/05/the-queens-gambit-the-chess-boom-and-the-future-of-chess/.

[6] D. M. D. Iliescu, "The Impact of Artificial Intelligence on the Chess World," *JMIR Serious Games*, vol. 8, no. 4, p. e24049, Dec. 2020. https://pmc.ncbi.nlm.nih.gov/articles/PMC7759436/.

[7] US Chess, "US Chess Guidelines for Accessible Chess Events," Apr. 2020. https://new.uschess.org/sites/default/files/wp-thumbnails/2020/04/Accessibility-Guidelines-April-2020.pdf.

[8] Davis, E. (2023, November 12). The Rise of Board Game Cafes: Socializing through Analog Entertainment. Medium. https://ethan-davis.medium.com/the-rise-of-board-game-cafes-socializing-through-analog-entertainment-51857183f856

[9] MFOSSociety. (n.d.). MFOSSociety/8-8: 8/8: Smart Chess Board: An Automated Ai Chess Board. GitHub. https://github.com/MFOSSociety/8-8 

[10] sumit11899. (n.d.). SUMIT11899/automated-chessboard. GitHub. https://github.com/sumit11899/Automated-ChessBoard 

[11] Simarmehta. (n.d.). Simarmehta/CHESSAUTOMATION_CV. GitHub. https://github.com/simarmehta/chessAutomation_CV 


## Statement of Contributions

Each team member must contribute meaningfully to the project proposal. In this section, each team member is required to document their individual contributions to the report. One team member may not record another member's contributions on their behalf. By submitting, the team certifies that each member's statement of contributions is accurate.
