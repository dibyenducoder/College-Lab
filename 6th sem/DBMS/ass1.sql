DROP TABLE emp CASCADE CONSTRAINTS;
DROP TABLE department CASCADE CONSTRAINTS;
DROP TABLE designation CASCADE CONSTRAINTS;

create table emp
(
emp_code char(5) primary key, 
emp_name char(20),
dept_code char(5),
desig_code char(5),
sex char(1),
address char(25),
city char(20), 
state char(20), 
pin char(6),
basic decimal(7,2),
jn_dt date
);
	
create table designation
(
desig_code char(5) primary key,
desig_desc char(20)
);
	
create table department
(
dept_code char(5) primary key,
dept_name char(15)
);

--describe emp;
--describe designation;
--describe department;

insert into designation values
    ('DES00', 'Authority');
insert into designation values
	('DES01', 'Manager');
insert into designation values
	('DES02', 'Executive');
insert into designation values
	('DES03', 'Officer');
insert into designation values
	('DES04', 'Clerk');
insert into designation values 
	('DES05','Helper');
	
insert into department values
    ('DP000','HOD');
insert into department values
	('DP001','Personnel');
insert into department values
	('DP002','Production');
insert into department values
	('DP003','Purchase');
insert into department values
	('DP004','Finance');	
insert into department values
	('DP005','Research');


insert into emp values('EM001', 'Dibyendu Mukhopdhyay', 'DP000', 'DES00','M','Jadavpur','Kolkata','West Bengal','700008','12345.67','17-FEB-2018');
insert into emp values('EM002', 'Mukesh Ambani', 'DP001', 'DES02','M','Delhi','Mumbai','Gujrat','700104',null,'1-FEB-2018');
insert into emp values('EM003', 'Some Name', null, 'DES01','F','Ranchi','A','B','700104',null,'1-FEB-2019');
insert into emp values('EM004', 'Abc Khan', null, 'DES02','M','Behala','Kolkata','Telengana','70104','0','23-NOV-2018');
insert into emp values('EM005', 'New Name', 'DP003', 'DES03','F','Sarsuna','qwe','rty','8301','3891','1-FEB-2017');


select * from emp where dept_code is null;
select * from emp where basic=0.0;
select * from emp where basic is null;

select avg(basic) from emp;

update emp set basic=0.0 where basic is null;

select avg(basic) from emp;

delete from emp where dept_code is null;

select emp_name, basic*0.5+basic*0.4+basic as net_pay from emp;

select upper(emp_name), basic from emp order by dept_code asc;

select * from emp where jn_dt > '01-JAN-1990';

select * from emp where extract(month from jn_dt) = 01;

select max(basic),min(basic) from emp;

select count(*) from emp where sex='F';

update emp set city=upper(city);

select count(distinct city) from emp;

select * from emp order by dept_code asc, basic desc;
