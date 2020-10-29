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
select * from designation;
	
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
select * from department;


insert into emp values('EM001', 'Bodhisatwa Mandal', 'DP000', 'DES00','M','Jadavpur','Kolkata','West Bengal','700008','12345.67','17-FEB-2018');
insert into emp values('EM002', 'Mukesh Ambani', 'DP001', 'DES02','M','Delhi','Mumbai','Gujrat','700104',null,'1-FEB-2018');
insert into emp values('EM003', 'Some Name', null, 'DES01','F','Ranchi','A','B','700104',null,'1-FEB-2019');
insert into emp values('EM004', 'Abc Khan', null, 'DES02','M','Behala','Kolkata','Telengana','70104','0','23-NOV-2018');
insert into emp values('EM005', 'New Name', 'DP003', 'DES03','F','Sarsuna','qwe','rty','8301','3891','1-FEB-2017');
select * from emp;

create table leave
(
	emp_code char(10),
	type char(2) constraint valid_type check(type in('CL','EL','ML')), 
	from_dt date, 
	to_dt date,
	foreign key(emp_code) references emp(emp_code),
	primary key(emp_code, type)
);
insert into leave values('EM001','CL','10-FEB-2019','11-FEB-2019');
insert into leave values('EM003','EL','12-FEB-2019','13-FEB-2019');
select * from leave;

--1
set serveroutput on;
declare
    name_of_emp emp.emp_name%type;
    desig_code emp.desig_code%type;
    code emp.emp_code%type;
begin
    code := 'EM006';
    select emp_name,desig_code into name_of_emp,desig_code from emp where emp.emp_code=code;
    dbms_output.put_line(name_of_emp||desig_code);
exception
    when no_data_found then
        dbms_output.put_line('Not Found');
end;

--2
declare
    e_code emp.emp_code%type := 'EM006'; 
    e_name emp.emp_name%type := 'New Name'; 
    dep_code emp.dept_code%type := 'HOD'; 
    des_code emp.desig_code%type := 'DES01'; 
    gen emp.sex%type := 'M'; 
    addr emp.address%type := 'Some Address'; 
    cit emp.city%type := 'Some City'; 
    sta emp.state%type := 'Some State'; 
    pi emp.pin%type := 70000; 
    bas emp.basic%type := 3232; 
    dt emp.jn_dt%type := '1-FEB-2017'; 
begin
    insert into emp values(e_code, e_name, dep_code, des_code, gen, addr, cit, sta, pi, bas, dt);
    dbms_output.put_line('Success');
exception
    when DUP_VAL_ON_INDEX then
        dbms_output.put_line('Data Duplicacy');
end;

--3 
select emp_name from emp order by basic fetch first 10 rows only;

--4
declare
    d_code emp.dept_code%type := 'DP000';
    var_rows number;
begin
    delete from emp where dept_code = d_code;
    if sql%found then
        var_rows := sql%rowcount;
        dbms_output.put_line('Rows Deleted :'||var_rows);
    else
        dbms_output.put_line('No Rows Deleted');
    end if;
end;
/

--5
create table ordermast
(
    order_no char(5) primary key,
    order_dt date
);

create table orderdetails
(
    order_no char(5),
    item_no char(5),
    qty number,
    primary key(order_no, item_no)
);

create table deliverymast
(
    delv_no char(5) primary key,
    order_no char(5),
    delv_dt date
);

create table delivery_details
(
    delv_no char(5),
    item_no char(5),
    qty number,
    primary key(delv_no, item_no)
);

declare
    dt_1 date;
    dt_2 date;


DROP TABLE emp CASCADE CONSTRAINTS;
DROP TABLE department CASCADE CONSTRAINTS;
DROP TABLE designation CASCADE CONSTRAINTS;