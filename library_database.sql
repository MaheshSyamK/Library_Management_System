DROP DATABASE IF EXISTS `Library_database`;
CREATE DATABASE `Library_database`;
USE `Library_database`;

SET NAMES utf8 ;
SET character_set_client = utf8mb4 ;

CREATE TABLE `student` (
    `student_id` INT AUTO_INCREMENT PRIMARY KEY,
    `first_name` VARCHAR(50),
    `last_name` VARCHAR(50),
    `birthdate` VARCHAR(15),
    `gender` VARCHAR(10),
    `grade` VARCHAR(10),
    `username` VARCHAR(100),
    `email` VARCHAR(100),
    `password` VARCHAR(100)
);

INSERT INTO `student` (`first_name`, `last_name`, `birthdate`, `gender`, `grade`, `username`, `email`, `password`) 
VALUES ('Jhon', 'Paul', '1999-07-12', 'm', '3.96', 'pj', 'path12@gmail.com', '1234eerrty');

INSERT INTO `student` (`first_name`, `last_name`, `birthdate`, `gender`, `grade`, `username`, `email`, `password`) 
VALUES ('Fate', 'Nasir', '1990-08-03', 'f', '3.7', 'fate12', 'fatenasir@gmail.com', 'fate1234');

CREATE TABLE `admin` (
    `admin_id` INT AUTO_INCREMENT PRIMARY KEY,
    `first_name` VARCHAR(50),
    `last_name` VARCHAR(50),
    `gender` VARCHAR(10),
    `username` VARCHAR(50),
    `email` VARCHAR(100),
    `password` VARCHAR(100)
); 

INSERT INTO `admin` (`first_name`, `last_name`, `gender`, `username`, `email`, `password`) 
VALUES ('Abebe', 'Kebede', 'm', 'abekebe', 'AB@gmail.com', '12AB34CD');

INSERT INTO `admin` (`first_name`, `last_name`, `gender`, `username`, `email`, `password`) 
VALUES ('Netsanet', 'Endale', 'f', 'netsi', 'netsanetendale@gmail.com', '1234netsi');

INSERT INTO `admin` (`first_name`, `last_name`, `gender`, `username`, `email`, `password`) 
VALUES ('Kemal', 'Abdu', 'm', 'keme', 'kemalabdu@gmail.com', '1234567890');

CREATE TABLE `books` (
    `book_id` INT AUTO_INCREMENT PRIMARY KEY,
    `title` VARCHAR(255),
    `author` VARCHAR(255),
    `publication_date` DATE,
    `department` VARCHAR(255),
    `status` VARCHAR(255)
);

INSERT INTO `books` (`title`, `author`, `publication_date`, `department`, `status`) 
VALUES ('Introduction to the Theory of Computation', 'Michael Sipser', '2012-02-14', 'Software_Engineering', 'Available');

INSERT INTO `books` (`title`, `author`, `publication_date`, `department`, `status`) 
VALUES ('Code Complete: A Practical Handbook of Software Construction', 'Steve McConnell', '2004-06-09', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (3, 'The Mythical Man-Month: Essays on Software Engineering', 'Frederick P. Brooks Jr.', '1995-08-12', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (4, 'Refactoring: Improving the Design of Existing Code', 'Martin Fowler', '1999-07-08', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (5, 'Structure and Interpretation of Computer Programs', 'Harold Abelson, Gerald Jay Sussman, Julie Sussman', '1996-07-15', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (6, 'The Art of Computer Programming', 'Donald E. Knuth', '1968-07-01', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (7, 'Software Engineering: A Practitioner\'s Approach', 'Roger S. Pressman, Bruce Maxim', '2014-03-28', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (8, 'Designing Data-Intensive Applications', 'Martin Kleppmann', '2017-03-16', 'Software_Engineering', 'Available');
INSERT INTO `books` VALUES    (9, 'Clean Architecture: A Craftsman\'s Guide to Software Structure and Design', 'Robert C. Martin', '2017-09-20', 'Software Engineering', 'Available');
INSERT INTO `books` VALUES    (10, 'Principles of Compiler Design', 'Alfred V. Aho, Jeffrey D. Ullman', '1977-01-01', 'Software Engineering', 'Available');
INSERT INTO `books` VALUES    (11, 'Microelectronic Circuits', 'Adel S. Sedra, Kenneth C. Smith', '2014-11-17', 'Electrical_Engineering', 'Available');
INSERT INTO `books` VALUES    (12, 'Electric Machinery Fundamentals', 'Stephen J. Chapman', '2017-02-10', 'Electrical_Engineering', 'Available');
INSERT INTO `books` VALUES    (13, 'Power System Analysis and Design', 'J. Duncan Glover, Thomas J. Overbye, Mulukutla S. Sarma', '2017-02-24', 'Electrical_Engineering', 'Available');
INSERT INTO `books` VALUES    (14, 'Digital Signal Processing', 'John G. Proakis, Dimitris G. Manolakis', '2013-09-13', 'Electrical_Engineering', 'Available');
INSERT INTO `books` VALUES    (15, 'Control Systems Engineering', 'Norman S. Nise', '2019-01-25', 'Electrical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (16, 'Fundamentals of Electric Circuits', 'Charles K. Alexander, Matthew N. O. Sadiku', '2012-02-03', 'Electrical_Engineering', 'Available');
INSERT INTO `books` VALUES    (17, 'Power Electronics: Converters, Applications, and Design', 'Ned Mohan, Tore M. Undeland, William P. Robbins', '2014-01-10', 'Electrical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (18, 'Signals and Systems', 'Alan V. Oppenheim, Alan S. Willsky, S. Hamid Nawab', '2013-07-12', 'Electrical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (19, 'Electromagnetic Fields and Waves', 'Paul Lorrain, Dale R. Corson, François Lorrain', '1990-12-15', 'Electrical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (20, 'Digital Communications', 'John G. Proakis, Masoud Salehi', '2013-08-12', 'Electrical_Engineering', 'Available');
INSERT INTO `books` VALUES    (21, 'Mechanics of Materials', 'Russell C. Hibbeler', '2017-01-15', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (22, 'Introduction to Thermal Systems Engineering: Thermodynamics, Fluid Mechanics, and Heat Transfer', 'Michael J. Moran, Howard N. Shapiro, Bruce R. Munson, David P. DeWitt', '2016-01-11', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (23, 'Engineering Mechanics: Statics', 'J. L. Meriam, L. G. Kraige', '2016-02-08', 'Mechanical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (24, 'Fundamentals of Fluid Mechanics', 'Bruce R. Munson, Donald F. Young, Theodore H. Okiishi, Wade W. Huebsch', '2015-02-02', 'Mechanical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (25, 'Machine Design: An Integrated Approach', 'Robert L. Norton', '2019-01-23', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (26, 'Heat and Mass Transfer: Fundamentals and Applications', 'Yunus A. Çengel, Afshin J. Ghajar', '2014-02-03', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (27, 'Engineering Mechanics: Dynamics', 'J. L. Meriam, L. G. Kraige, Jeffrey N. Bolton', '2015-08-11', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (28, 'Fluid Mechanics: Fundamentals and Applications', 'Yunus A. Çengel, John M. Cimbala', '2017-01-18', 'Mechanical_Engineering', 'Available');
 INSERT INTO `books` VALUES   (29, 'Shigley\'s Mechanical Engineering Design', 'Richard G. Budynas, Keith J. Nisbett', '2014-09-08', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (30, 'Engineering Vibration', 'Daniel J. Inman', '2013-03-13', 'Mechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (31, 'Electromechanical Systems and Devices', 'Sergey Edward Lyshevski', '2016-09-14', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES    (32, 'Electromechanical Energy Conversion: Dynamics, Machines, and Drives', 'David J. Braun', '2017-03-21', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES   (33, 'Introduction to Mechatronics and Measurement Systems', 'David G. Alciatore, Michael B. Histand', '2018-01-03', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(34, 'Electric Motors and Drives: Fundamentals, Types and Applications', 'Austin Hughes, Bill Drury', '2013-08-06', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(35, 'Mechatronics: Principles and Applications', 'Godfrey C. Onwubolu', '2016-08-04', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(36, 'Sensors and Actuators: Control System Instrumentation', 'Clarence W. de Silva', '2018-07-24', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(37, 'Electromechanical Dynamics, Part I: Discrete Systems', 'Herbert H. Woodson, James R. Melcher', '2012-10-29', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(38, 'Robotics: Modelling, Planning and Control', 'Bruno Siciliano, Lorenzo Sciavicco, Luigi Villani, Giuseppe Oriolo', '2010-07-20', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(39, 'Electric Drives and Electromechanical Systems: Applications and Control', 'Richard Crowder', '2018-12-11', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES (40, 'Introduction to Robotics: Mechanics and Control', 'John J. Craig', '2018-05-18', 'Electromechanical_Engineering', 'Available');
INSERT INTO `books` VALUES(41, 'Structural Analysis', 'Russell C. Hibbeler', '2018-02-06', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(42, 'Reinforced Concrete: Mechanics and Design', 'James K. Wight, James G. MacGregor', '2014-01-24', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(43, 'Geotechnical Engineering: Principles and Practices', 'Donald P. Coduto, William A. Kitch, Man-Chu Ronald Yeung', '2010-08-31', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(44, 'Transportation Engineering: An Introduction', 'C. Jotin Khisty, B. Kent Lall', '2015-08-31', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(45, 'Water Resources Engineering', 'Larry W. Mays', '2010-10-25', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(46, 'Construction Planning, Equipment, and Methods', 'Robert L. Peurifoy, Clifford J. Schexnayder, Aviad Shapira, Robert Schmitt', '2010-07-02', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(47, 'Environmental Engineering: Fundamentals, Sustainability, Design', 'James R. Mihelcic, Julie B. Zimmerman', '2016-01-27', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(48, 'Highway Engineering', 'Roger L. Brockenbrough, Kenneth J. Boedecker', '2009-08-01', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(49, 'Fundamentals of Structural Analysis', 'Kenneth M. Leet, Chia-Ming Uang, Joel T. Lanning', '2017-04-13', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(50, 'Soil Mechanics and Foundations', 'Muni Budhu', '2013-08-30', 'Civil_Engineering', 'Available');
INSERT INTO `books` VALUES(51, 'Architecture: Form, Space, and Order', 'Francis D. K. Ching', '2014-09-15', 'Architecture', 'Available');
INSERT INTO `books` VALUES(52, 'The Architecture Reference & Specification Book: Everything Architects Need to Know Every Day', 'Julia McMorrough', '2013-05-07', 'Architecture', 'Available');
INSERT INTO `books` VALUES(53, 'Architectural Graphics', 'Francis D. K. Ching', '2015-03-16', 'Architecture', 'Available');
INSERT INTO `books` VALUES(54, 'Architectural Drawing: A Visual Compendium of Types and Methods', 'Rendow Yee', '2012-09-04', 'Architecture', 'Available');
INSERT INTO `books` VALUES(55, 'Building Construction Illustrated', 'Francis D. K. Ching', '2014-02-03', 'Architecture', 'Available');
INSERT INTO `books` VALUES(56, 'The Future of Architecture in 100 Buildings', 'Marc Kushner', '2015-03-10', 'Architecture', 'Available');
INSERT INTO `books` VALUES(57, '101 Things I Learned in Architecture School', 'Matthew Frederick', '2007-08-01', 'Architecture', 'Available');
INSERT INTO `books` VALUES(58, 'Time-Saver Standards for Architectural Design', 'Michael J. Crosbie', '2017-03-20', 'Architecture', 'Available');
INSERT INTO `books` VALUES(59, 'The Architecture Student''s Handbook of Professional Practice', 'American Institute of Architects', '2013-08-12', 'Architecture', 'Available');
INSERT INTO `books` VALUES(60, 'Architectural Acoustics', 'David Egan', '2007-07-24', 'Architecture', 'Available');
INSERT INTO `books` VALUES(61, 'Introductory Mining Engineering', 'Howard L. Hartman, Jan M. Mutmansky', '2002-08-09', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(62, 'SME Mining Engineering Handbook', 'Peter Darling (Editor)', '2011-02-01', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(63, 'Hardrock Seismic Exploration', 'Terry Engelder', '2001-09-25', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(64, 'Mining Economics and Strategy', 'Ian C. Runge', '1998-09-01', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(65, 'Surface Mining: Second Edition', 'Kenneth S. Kutchta, Austin S. Kuhn', '1999-01-01', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(66, 'Mine Ventilation and Air Conditioning', 'Howard L. Hartman, Jan M. Mutmansky', '2005-08-12', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(67, 'Mining and the Environment: From Ore to Metal', 'Karlheinz Spitz, John Trudinger', '2016-09-01', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(68, 'Open Pit Mine Planning and Design: Fundamentals, CSMine Software Package, CD-ROM', 'William A. Hustrulid, Mark Kuchta, Randall K. Martin', '2006-06-30', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(69, 'Blasting Principles for Open Pit Mining', 'William A. Hustrulid, William Hustrulid', '1999-01-01', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(70, 'Rock Mechanics for Underground Mining', 'B.H.G. Brady, E.T. Brown', '2004-12-15', 'Mining_Engineering', 'Available');
INSERT INTO `books` VALUES(71, 'Introduction to Environmental Engineering and Science', 'Gilbert M. Masters, Wendell P. Ela', '2014-01-21', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(72, 'Water and Wastewater Engineering', 'Mackenzie L. Davis, David A. Cornwell', '2010-01-19', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(73, 'Environmental Science and Engineering', 'J. Glynn Henry, Gary W. Heinke', '2008-02-27', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(74, 'Air Pollution: Its Origin and Control', 'Kenneth Wark, Cecil F. Warner, Wayne T. Davis', '2012-01-01', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(75, 'Solid Waste Engineering: A Global Perspective', 'William A. Worrell, P. Aarne Vesilind, Christian Ludwig', '2011-10-03', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(76, 'Environmental Engineering: Fundamentals, Sustainability, Design', 'James R. Mihelcic, Julie B. Zimmerman', '2016-01-27', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(77, 'Water Resources Engineering', 'Larry W. Mays', '2010-10-25', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES(78, 'Principles of Environmental Engineering and Science', 'Mackenzie L. Davis, Susan J. Masten', '2019-07-26', 'Environmental_Engineering', 'Available');
 INSERT INTO `books` VALUES (79, 'Environmental Biotechnology: Principles and Applications', 'Bruce Rittmann, Perry L. McCarty', '2011-01-01', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES  (80, 'Environmental Chemistry', 'Stanley E. Manahan', '2009-05-08', 'Environmental_Engineering', 'Available');
INSERT INTO `books` VALUES  (81, 'Industrial Chemistry: For Advanced Students', 'Jack Appleton, Heinrich Offermanns', '2010-09-01', 'Industrial_Chemistry', 'Available');
INSERT INTO `books` VALUES  (82, 'Industrial Chemistry: Organic', 'Allen B. Crow, Frederick H. Getzen', '1992-01-01', 'Industrial_Chemistry', 'Available');
INSERT INTO `books` VALUES  (83, 'Industrial Chemistry: Inorganic', 'Allen B. Crow, Frederick H. Getzen', '1992-01-01', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (84, 'Industrial Chemistry: Environmental Impact', 'Terence J. Collins, Thomas R. Kurfurst', '2002-08-01', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (85, 'Industrial Chemistry: Principles and Applications', 'Chris A. Clausen III, Guy Mattson', '2012-10-19', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (86, 'Introduction to Industrial Chemistry', 'Paul T. Anastas, Julianne M. Ando', '2020-08-18', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (87, 'Industrial Chemistry: For Advanced Students', 'W. Keim', '2019-05-01', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (88, 'Industrial Chemistry: Theory and Practice', 'Achim Schmidt', '2017-06-22', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (89, 'Industrial Chemistry: Pharmaceuticals', 'Chittaranjan B. Kole', '2017-09-27', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (90, 'Industrial Chemistry: For Advanced Students', 'Michele Aresta, Angela Dibenedetto, Franck Dumeignil', '2021-07-01', 'Industrial_Chemistry', 'Available');
 INSERT INTO `books` VALUES (91, 'Principles of Igneous and Metamorphic Petrology', 'Anthony Philpotts, Jay Ague', '2009-05-29', 'Geology', 'Available');
INSERT INTO `books` VALUES(92, 'Structural Geology', 'Haakon Fossen', '2015-12-11', 'Geology', 'Available');
 INSERT INTO `books` VALUES (93, 'Sedimentary Geology', 'Donald R. Prothero, Fred Schwab', '2018-11-01', 'Geology', 'Available');
 INSERT INTO `books` VALUES (94, 'The Geology of Ore Deposits', 'John M. Guilbert, Charles F. Park Jr.', '2007-12-28', 'Geology', 'Available');
 INSERT INTO `books` VALUES (95, 'Principles of Geotechnical Engineering', 'Braja M. Das, Khaled Sobhan', '2017-01-01', 'Geology', 'Available');
 INSERT INTO `books` VALUES   (96, 'Earth: Portrait of a Planet', 'Stephen Marshak', '2015-09-25', 'Geology', 'Available');
  INSERT INTO `books` VALUES  (97, 'Geomorphology', 'Biddy Passmore', '2019-03-15', 'Geology', 'Available');
  INSERT INTO `books` VALUES  (98, 'Environmental Geology', 'Carla W. Montgomery', '2012-01-01', 'Geology', 'Available');
  INSERT INTO `books` VALUES  (99, 'Introduction to Mineralogy', 'William D. Nesse', '2011-09-13', 'Geology', 'Available');
   INSERT INTO `books` VALUES (100, 'Introduction to Geochemistry: Principles and Applications', 'Kula C. Misra', '2012-09-17', 'Geology', 'Available');
   INSERT INTO `books` VALUES (101, 'Food Chemistry', 'H.-D. Belitz, Werner Grosch, Peter Schieberle', '2016-02-11', 'Food_Science', 'Available');
   INSERT INTO `books` VALUES (102, 'Food Science', 'Norman N. Potter, Joseph H. Hotchkiss', '1998-07-01', 'Food_Science', 'Available');
   INSERT INTO `books` VALUES (103, 'Introduction to Food Science and Food Systems', 'Rick Parker, Miriah Pace', '2020-02-07', 'Food_Science', 'Available');
   INSERT INTO `books` VALUES (104, 'Food Processing Technology: Principles and Practice', 'P.J. Fellows', '2016-02-23', 'Food_Science', 'Available');
  INSERT INTO `books` VALUES  (105, 'Food Microbiology: Fundamentals and Frontiers', 'Michael P. Doyle, Robert L. Buchanan', '2012-03-26', 'Food_Science', 'Available');
  INSERT INTO `books` VALUES  (106, 'Food Microbiology', 'Michael ', '2012-03-26', 'Food_Science', 'Available');
  INSERT INTO `books` VALUES  (107, 'Food Science and Technology', 'Geoffrey Campbell-Platt', '2018-08-31', 'Food_Science', 'Available');
  INSERT INTO `books` VALUES  (108, 'Food Packaging Science and Technology', 'Gordon L. Robertson', '2012-01-09', 'Food_Science', 'Available');
   INSERT INTO `books` VALUES (109, 'Food Rheology and Texture', 'Howard R. Moskowitz, Talia Mizrahi', '2013-06-03', 'Food_Science', 'Available');
   INSERT INTO `books` VALUES (110, 'Food Engineering: Integrated Approaches', 'Gustavo V. Barbosa-Cánovas, Maria Cecilia do Amaral Sobral, Pablo Juliano', '2013-01-03', 'Food_Science', 'Available');
   INSERT INTO `books` VALUES (111, 'Molecular Biotechnology: Principles and Applications of Recombinant DNA', 'Bernard R. Glick, Jack J. Pasternak', '2019-08-23', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (112, 'Bioprocess Engineering Principles', 'Pauline M. Doran', '2012-12-14', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (113, 'Biotechnology: An Introduction', 'Susan R. Barnum', '2016-12-29', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (114, 'Principles of Fermentation Technology', 'Peter F. Stanbury, Allan Whitaker, Stephen J. Hall', '2016-04-18', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (115, 'Genetic Engineering: Principles and Methods', 'Jane K. Setlow', '2019-11-27', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (116, 'Introduction to Biotechnology', 'William J. Thieman, Michael A. Palladino', '2018-01-01', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (117, 'Industrial Biotechnology: Products and Processes', 'Chapman and Hall', '2017-01-12', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (118, 'Biotechnology: Science for the New Millennium', 'Ellyn Daugherty', '2016-03-02', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (119, 'Basic Biotechnology', 'Colin Ratledge, Bjorn Kristiansen', '2013-05-14', 'Biotechnology', 'Available');
   INSERT INTO `books` VALUES (120, 'Biotechnology: Academic Cell Update Edition', 'David P. Clark, Nanette J. Pazdernik', '2019-05-15', 'Biotechnology', 'Available');


  