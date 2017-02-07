-- MySQL dump 10.13  Distrib 5.5.24, for debian-linux-gnu (x86_64)
--
-- Host: localhost    Database: funnymonkey_import
-- ------------------------------------------------------
-- Server version	5.5.24-3

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `country`
--

DROP TABLE IF EXISTS `country`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `country` (
  `id` int(11) NOT NULL,
  `country` varchar(255) DEFAULT NULL,
  `sort` int(11) DEFAULT NULL,
  `display` char(1) DEFAULT NULL,
  `regionID` int(11) DEFAULT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `course`
--

DROP TABLE IF EXISTS `course`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `course` (
  `courseID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `abbreviation` varchar(255) NOT NULL,
  `controllerID` int(11) DEFAULT NULL,
  `imageFile` varchar(255) DEFAULT NULL,
  `passPercentage` int(11) DEFAULT NULL,
  `createDate` varchar(255) NOT NULL,
  `updateDate` varchar(255) DEFAULT NULL,
  `nbrofPages` int(11) NOT NULL,
  `styleID` int(11) NOT NULL,
  `summary` varchar(255) DEFAULT NULL,
  `purpose` text,
  `objective` text,
  `udTitle` varchar(255) DEFAULT NULL,
  `udText` varchar(255) DEFAULT NULL,
  `timeLength` varchar(255) DEFAULT NULL,
  `displayOrder` int(11) NOT NULL,
  `published` TINYINT(1) NOT NULL,
  `private` TINYINT(1) NOT NULL,
  `otherTitle` varchar(255) DEFAULT NULL,
  `otherText` text,
  `publishedDate` varchar(255) DEFAULT NULL,
  `reference` text,
  `examIntro` text,
  `examPassMark` int(11) NOT NULL,
  `courseCredit` text,
  `lastUpdateDate` varchar(255) DEFAULT NULL,
  `deleted` TINYINT(1) NOT NULL,
  `courseManager` varchar(255) DEFAULT NULL,
  `displayCourseManager` TINYINT(1) NOT NULL,
  `courseAuthor` varchar(255) DEFAULT NULL,
  `displayCourseAuthor` TINYINT(1) NOT NULL,
  `accessLevelID` tinyint(4) NOT NULL,
  `memberCategoryID` int(11) DEFAULT NULL,
  PRIMARY KEY (`courseID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `courseGlossary`
--

DROP TABLE IF EXISTS `courseGlossary`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `courseGlossary` (
  `courseID` int(11) NOT NULL,
  `glossaryID` int(11) NOT NULL,
  PRIMARY KEY (`courseID`,`glossaryID`),
  KEY `glossaryID` (`glossaryID`),
  CONSTRAINT `courseGlossary_ibfk_1` FOREIGN KEY (`glossaryID`) REFERENCES `glossary` (`glossaryID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `examStatus`
--

DROP TABLE IF EXISTS `examStatus`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `examStatus` (
  `examStatusID` int(11) NOT NULL,
  `memberID` int(11) NOT NULL,
  `courseID` int(11) NOT NULL,
  `passMark` int(11) NOT NULL,
  `examMark` int(11) NOT NULL,
  `passDate` varchar(255) NOT NULL,
  `examComplete` TINYINT(1) NOT NULL,
  `actionplanComplete` TINYINT(1) NOT NULL,
  `evaluationComplete` TINYINT(1) NOT NULL,
  PRIMARY KEY (`examStatusID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `glossary`
--

DROP TABLE IF EXISTS `glossary`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `glossary` (
  `glossaryID` int(11) NOT NULL,
  `courseID` int(11) DEFAULT NULL,
  `term` varchar(255) NOT NULL,
  `termDefinition` text,
  PRIMARY KEY (`glossaryID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `glossaryPatch`
--

DROP TABLE IF EXISTS `glossaryPatch`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `glossaryPatch` (
  `glossaryID` int(10) unsigned NOT NULL,
  `use_glossaryID` int(10) unsigned DEFAULT NULL,
  `term` varchar(255) DEFAULT NULL,
  `unused1` int(11) DEFAULT NULL,
  `new_term` varchar(255) DEFAULT NULL,
  `termDefinition` text,
  `courseID` int(10) unsigned DEFAULT NULL,
  `courseName` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`glossaryID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;


--
-- Table structure for table `member`
--

DROP TABLE IF EXISTS `member`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `member` (
  `memberID` int(11) NOT NULL,
  `memberTypeID` int(11) NOT NULL,
  `CreateDate` varchar(255) NOT NULL,
  `UpdateDate` varchar(255) DEFAULT NULL,
  `Username` varchar(255) DEFAULT NULL,
  `Password` varchar(255) NOT NULL,
  `Firstname` varchar(255) NOT NULL,
  `Lastname` varchar(255) NOT NULL,
  `Address1` varchar(255) DEFAULT NULL,
  `Address2` varchar(255) DEFAULT NULL,
  `City` varchar(255) DEFAULT NULL,
  `State` varchar(255) DEFAULT NULL,
  `ZipCode` varchar(255) DEFAULT NULL,
  `Country` varchar(255) DEFAULT NULL,
  `Email` varchar(255) NOT NULL,
  `HomePhone` varchar(255) DEFAULT NULL,
  `SharedYN` TINYINT(1) DEFAULT NULL,
  `Picture` varchar(255) DEFAULT NULL,
  `Statusid` int(11) NOT NULL,
  `lastLogin` varchar(255) NOT NULL,
  `CountryID` int(11) DEFAULT NULL,
  `organization` varchar(255) DEFAULT NULL,
  `occupation` varchar(255) DEFAULT NULL,
  `categoryID` int(11) DEFAULT NULL,
  `globalReadAccess` TINYINT(1) NOT NULL,
  `manageMember` TINYINT(1) NOT NULL,
  `manageCourse` TINYINT(1) NOT NULL,
  `viewReports` TINYINT(1) NOT NULL,
  `editContent` TINYINT(1) NOT NULL,
  `sendMail` TINYINT(1) NOT NULL,
  `active` TINYINT(1) NOT NULL,
  `getMail` TINYINT(1) NOT NULL,
  `isUSAID` TINYINT(1) NOT NULL,
  `sex` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`memberID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `memberProgramComplete`
--

DROP TABLE IF EXISTS `memberProgramComplete`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `memberProgramComplete` (
  `memberProgramID` int(11) NOT NULL,
  `memberId` int(11) NOT NULL,
  `programId` int(11) NOT NULL,
  `dateCompleted` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`memberProgramID`),
  KEY `programId` (`programId`),
  CONSTRAINT `memberProgramComplete_ibfk_1` FOREIGN KEY (`programId`) REFERENCES `program` (`programID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `page`
--

DROP TABLE IF EXISTS `page`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `page` (
  `pageID` int(11) NOT NULL,
  `topicID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `pageNavLabel` varchar(255) NOT NULL,
  `content` text NOT NULL,
  `imageFile` varchar(255) DEFAULT NULL,
  `imageWidth` int(11) DEFAULT NULL,
  `imageHeight` int(11) DEFAULT NULL,
  `imageAltText` varchar(255) DEFAULT NULL,
  `imageCaption` varchar(255) DEFAULT NULL,
  `element1Type` int(11) DEFAULT NULL,
  `element1Text` text,
  `element2Type` int(11) DEFAULT NULL,
  `element2Text` text,
  `pageTipText` text,
  `displayOrder` int(11) NOT NULL,
  `createDate` varchar(255) NOT NULL,
  `updateDate` varchar(255) NOT NULL,
  `editUserID` int(11) DEFAULT NULL,
  `published` int(11) NOT NULL,
  `publishedDate` varchar(255) DEFAULT NULL,
  `deleted` TINYINT(1) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `program`
--

DROP TABLE IF EXISTS `program`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `program` (
  `programID` int(11) NOT NULL,
  `Name` varchar(255) NOT NULL,
  `abbreviation` varchar(255) NOT NULL,
  `Description` text,
  `displayOrder` int(11) NOT NULL,
  `updateDate` varchar(255) DEFAULT NULL,
  `published` TINYINT(1) NOT NULL,
  `deleted` TINYINT(1) NOT NULL,
  `private` TINYINT(1) NOT NULL,
  `publisheddate` varchar(255) DEFAULT NULL,
  `import_courses` text, -- Manually filled.
  PRIMARY KEY (`programID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `programcourse`
--

DROP TABLE IF EXISTS `programcourse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `programcourse` (
  `id` int(11) NOT NULL,
  `programId` int(11) NOT NULL,
  `courseId` int(11) NOT NULL,
  `displayOrder` int(11) NOT NULL,
  PRIMARY KEY (`id`),
  KEY `programId` (`programId`),
  CONSTRAINT `programcourse_ibfk_1` FOREIGN KEY (`programId`) REFERENCES `program` (`programID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `question`
--

DROP TABLE IF EXISTS `question`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `question` (
  `questionID` int(11) NOT NULL,
  `question` text NOT NULL,
  `questionTypeID` int(11) NOT NULL,
  `createDate` varchar(255) NOT NULL,
  `updateDate` varchar(255) DEFAULT NULL,
  `topicID` int(11) NOT NULL,
  `displayOrder` tinyint(4) NOT NULL,
  `knowledgeCheck` TINYINT(1) NOT NULL,
  `knowledgeRecap` TINYINT(1) NOT NULL,
  `exam` TINYINT(1) NOT NULL,
  `checkDisplayOrder` tinyint(4) DEFAULT NULL,
  `recapDisplayOrder` tinyint(4) DEFAULT NULL,
  `examDisplayOrder` tinyint(4) DEFAULT NULL,
  `displaySelect` TINYINT(1) NOT NULL,
  `eval` TINYINT(1) NOT NULL,
  `evalDisplayOrder` tinyint(4) DEFAULT NULL,
  `explanation` text,
  `pageID` int(11) DEFAULT NULL,
  `deleted` TINYINT(1) NOT NULL,
  PRIMARY KEY (`questionID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `questionResponse`
--

DROP TABLE IF EXISTS `questionResponse`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `questionResponse` (
  `responseID` int(11) NOT NULL,
  `response` text,
  `questionID` int(11) NOT NULL,
  `responseExplanation` text,
  `correctAnswer` TINYINT(1) NOT NULL,
  `displayOrder` tinyint(4) NOT NULL,
  `responseQuestion` varchar(255) DEFAULT NULL,
  PRIMARY KEY (`responseID`),
  KEY `questionID` (`questionID`),
  CONSTRAINT `questionResponse_ibfk_1` FOREIGN KEY (`questionID`) REFERENCES `question` (`questionID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `questionType`
--

DROP TABLE IF EXISTS `questionType`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `questionType` (
  `questionTypeID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  PRIMARY KEY (`questionTypeID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `topic`
--

DROP TABLE IF EXISTS `topic`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!40101 SET character_set_client = utf8 */;
CREATE TABLE `topic` (
  `topicID` int(11) NOT NULL,
  `name` varchar(255) NOT NULL,
  `courseID` int(11) DEFAULT NULL,
  `icon` varchar(255) NOT NULL,
  `timeLength` varchar(255) NOT NULL,
  `displayOrder` int(11) NOT NULL,
  `keypoints` text,
  `deleted` TINYINT(1) NOT NULL,
  PRIMARY KEY (`topicID`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2012-06-21 15:06:01
