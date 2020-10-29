--1
create table department
(
	dept_code char(10) primary key,
	dept_name char(30)
);
insert into department values('D1','CSE');
insert into department values('D2','ETCE');
insert into department values('D3','EE');
select * from department;

create table employee
(
	emp_code char(10) primary key,
	dept_code char(10),
	emp_name char(30) constraint upper_case_name check (emp_name=upper(emp_name)),
	address char(50), 
	dt_jn date default sysdate,
	grade char(1) constraint grade_valid check (grade in ('A','B','C')), 
	basic number(7,2) constraint sal_chk check (basic>= 5000 and basic<=9000),
	constraint dept_fkey foreign key(dept_code) references department(dept_code)
);
insert into employee values('E1','D1','ABC','Kolkata','1-FEB-2019','A','7000');
insert into employee values('E2','D2','DEF','Delhi','2-FEB-2019','B','8000');
insert into employee values('E3','D3','ABC','Behala','3-FEB-2019','C','6000');
insert into employee values('E4','D1','XYZ','Jadavpur','10-FEB-2019','B','8000');
select * from employee;

create table leave
(
	emp_code char(10),
	type char(2) constraint valid_type check(type in('CL','EL','ML')), 
	from_dt date, 
	to_dt date,
	foreign key(emp_code) references employee(emp_code),
	primary key(emp_code, type)
);
insert into leave values('E1','CL','10-FEB-2019','11-FEB-2020');
insert into leave values('E3','EL','12-FEB-2019','13-FEB-2020');
select * from leave;

--2
insert into leave values('E2','AB','10-FEB-2019','11-FEB-2019');

--3a
create table personnel
(
	emp_code primary key,
	emp_name,
	dept_name,
	basic
)
as select emp_code, emp_name, dept_name, basic from employee,
	department where employee.dept_code=department.dept_code
	and basic=7000 
	and department.dept_code='D3';

--3b
insert into personnel
	select emp_code, emp_name, dept_name, basic from employee, department 
	where employee.dept_code=department.dept_code
	and basic>=7000
	and emp_code not in (select distinct emp_code from personnel);
select * from personnel;

--3c
alter table personnel add (net_pay number(10));
select * from personnel;

--3d
update personnel set net_pay=1.5*basic;
select * from personnel;

--3e
alter table personnel drop column net_pay;
select * from personnel;

--4
drop table personnel;
drop table leave;
drop table employee;
drop table department;