
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


insert into emp values('EM001', 'Dibu', 'DP000', 'DES00','M','Jadavpur','Kolkata','West Bengal','700008','12345.67','17-FEB-2018');
insert into emp values('EM002', 'Mukesh Ambani', 'DP001', 'DES02','M','Delhi','Mumbai','Gujrat','700104','512','1-FEB-2018');
insert into emp values('EM003', 'Some Name', 'DP001', 'DES01','F','Ranchi','A','B','700104','1000','1-FEB-2019');
insert into emp values('EM004', 'Abc Khan', 'DP000', 'DES02','M','Behala','Kolkata','Telengana','70104','0','23-NOV-2018');
insert into emp values('EM005', 'New Name', 'DP003', 'DES03','F','Sarsuna','qwe','rty','8301','3891','1-FEB-2017');

--1
select dept_code, max(basic), min(basic), avg(basic) from emp group by dept_code order by dept_code;

--2
select dept_code,count(*) as fem_count from emp  where sex='F' group by dept_code;

--3
select city, count(*) as emp_count_in_city from emp group by city;

--4
select desig_code, count(*) as count_desig from emp where jn_dt between '1-JAN-2000' and '31-DEC-2999' group by desig_code order by count(*);

--5
select sum(basic),dept_code from emp where sex='M' group by dept_code having sum(basic)>50000 order by sum(basic) desc;

--6
select emp.emp_name, designation.desig_desc, emp.basic from emp,designation where emp.desig_code=designation.desig_code;

--7
select emp.emp_name, designation.desig_desc, department.dept_name, emp.basic from emp,designation,department where emp.desig_code=designation.desig_code and 
emp.dept_code=department.dept_code;

--8
select department.dept_name from emp,department where (select count(*) from emp where emp.dept_code=department.dept_code)=0 group by department.dept_name;

--9
select department.dept_name from emp,department where (select count(*) from emp where emp.dept_code=department.dept_code)>0 group by department.dept_name;

--10
select department.dept_name from emp,department where (select count(*) from emp where emp.dept_code=department.dept_code)>=10 group by department.dept_name;

--11
select dept_code from emp where basic = (select max(basic) from emp);

--12
select designation.desig_desc from designation  where designation.desig_code=(select desig_code from emp where basic>=all(select distinct basic from emp));

--13
select dept_code,count(*) as count from emp where desig_code=(select desig_code from designation where desig_desc='Manager') group by dept_code;

--14
select emp.emp_code, emp.emp_name, emp.basic from emp where emp.basic>=all(select distinct basic from emp);

--15
select emp.emp_code, emp.emp_name, emp.basic from emp where emp.basic<=all(select distinct basic from emp);

--16
select dept_name from department where dept_code in (select dept_code from emp where basic>=all(select basic from emp));
select dept_name from department where dept_code in (select dept_code from emp group by dept_code having avg(basic)>=all(select avg(basic) from emp group by dept_code));
select dept_code from department where dept_code in (select dept_code from emp group by dept_code having count(*)>all(select count(*) from emp group by dept_code));

--17
insert into emp values
	('EM224', 'ABCEEF GHIJKL', 'DP001', 'DE007','M','1 Gariahat','New Delhi','Delhi','134711','12345.67','17-FEB-2014');

--18
delete from emp where desig_code not in (select desig_code from designation);

--19
select emp_name from emp outer_emp where outer_emp.sex='F' and basic<all (select avg(inner_emp.basic) from emp inner_emp where 
inner_emp.dept_code=outer_emp.dept_code);

--20
select count(*) as female_manager_count from emp where desig_code in (select desig_code from designation where desig_desc='Manager' ) and sex='F';

DROP TABLE emp CASCADE CONSTRAINTS;
DROP TABLE department CASCADE CONSTRAINTS;
DROP TABLE designation CASCADE CONSTRAINTS;