.header on
.width 0 20 25 15
.mode column
PRAGMA foreign_keys = ON;
-- creating Country table and adding values
create table Country
(CId int primary key,CName varchar(30) not null,no_of_states int not null);

-- inserting values int0 Country table 
insert into Country values
(1001,"India",28),
(1002,"Australia",6),
(1003,"South Africa",9),
(1004,"Sri Lanka",9),
(1005,"Germany",16)
;

-- creating Cities table and adding values
create table Cities
(cityId int primary key,cityName varchar(50) not null,pinCode varchar(20)not null,population int not null,CId int, FOREIGN KEY(CId) REFERENCES Country(CId));


insert into Cities values(101,"Pune","41107",3124458,1001);
insert into Cities values(102,"Mumbai","31107",2000000,1001);
insert into Cities values(103,"Delhi","31107",18983000,1001);
insert into Cities values(104,"Sydney","4532",5301000,1002);
insert into Cities values(105,"Melbourne","7532",5008000,1002);
insert into Cities values(106,"Perth","4352",1908000,1002);
insert into Cities values(107,"Cape Town","54724",4621000,1003);
insert into Cities values(108,"Johannesburg","54324",5641000,1003);
insert into Cities values(109,"Durban","54311",3721000,1003);
insert into Cities values(110,"Colombo","95327",5648000,1004);
insert into Cities values(111,"Kandy","081",130000,1004);
insert into Cities values(112,"Galle","957",93000,1004);
insert into Cities values(113,"Berlin","2137",3080000,1005);
insert into Cities values(114,"Munich","9327",1048000,1005);
insert into Cities values(115,"Frankfrut","9227",730000,1005);

-- Example of select
.print
.print Example of SELECT clause :
select * from Country;
.print
select * from Cities;
.print
select * from Country where CName="India";
.print
select * from Country where not CName="India";
.print
select cityId,cityName  from Cities where cityName="Pune" or cityId=102;
.print
select cityName from Cities where not cityName="Pune" and population>100000;
.print
select CName,count(*) from Country,Cities where Country.CId=Cities.CId group by Country.CId;
.print
select sum(population) from Cities;
.print
select cityId,cityName,population from Cities order by cityName;
.print
.print
.print Update on Country table
.print
select * from Country where CName="Australia";
.print
Update Country set no_of_states=no_of_states+1 where CName="Australia";
.print
select * from Country where CName="Australia";
.print
.print Delete on Cities table
.print
select * from Cities where cityName="Galle";
.print
Delete from Cities where cityName="Galle";
.print
select cityName from Cities;
