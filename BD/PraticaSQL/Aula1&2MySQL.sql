create database BD_SQL_1;
crko38eate database if not exists dbdemo;

use BD_SQL_1;
use dbdemo;

create table CadFun(
CodFun integer not null primary key,
Nome varchar(40)not null,
Depto char(2),
Funcao char(20),
Salario decimal(10,2)
);

create table Categories(
cat_id int not null auto_increment primary key,
cat_name varchar(50),
cat_description text
);

create table Products(
prd_id int not null auto_increment primary key,
prd_name varchar(355) not null,
prd_price decimal,
cat_id int not null,

foreign key fk_cat(cat_id)
references Categories(cat_id)
on update cascade
on delete restrict
);

create table vendors(
vdr_id int not null auto_increment primary key,
vdr varchar(255)
)
engine=InnoDB;

alter table products add column vdr_id int not null after cat_id;

show create table Products;
show tables;

INSERT INTO products (prd_name, prd_price,cat_id, vdr_id) VALUES
('Smartphone Galaxy A14', 199.99, 1,21),
('Camiseta Básica Preta', 15.50, 2,20),
('Arroz Agulhinha 5kg', 4.99, 3,2),
('O Senhor dos Anéis', 25.00, 4,10),
('Cadeira de Escritório', 89.90, 5,30),
('Notebook Dell Inspiron', 899.00, 1,9),
('Calça Jeans Masculina', 35.90, 2,8),
('Feijão Preto 1kg', 2.49, 3,5),
('1984 - George Orwell', 18.70, 4,67),
('Mesa de Jantar 4 lugares', 150.00, 5,12);

set foreign_key_checks = 0;

INSERT INTO CadFun(CodFun,Nome,Depto,Funcao,Salario)VALUE(12,'Carlos Alberto','3','Vendedor',1530.00);
INSERT INTO CadFun(CodFun,Nome,Depto,Funcao,Salario)VALUE(37,'Augusto Souza','4','Programador',1050.00);
INSERT INTO CadFun(CodFun,Nome,Depto,Funcao,Salario)VALUE(57,'John Smith','4','Programador',2000.00);

select * from CadFun;
select * from Categories;
select * from Products;

select Nome,CodFun from CadFun where depto='4'and salario>=1000.00;

update CadFun set Salario=35000.00 where CodFun=37;

delete from CadFun where CodFun=57;

alter table CadFun add DataAdmicao date;
update CadFun set DataAdmicao="2019-04-01" where CodFun=12;

select * from CadFun where Nome like '_u%a';
select * from CadFun where (Depto='4') xor (Funcao='Programador');

alter table CadFun add Filhos smallint;

select Nome,Filhos from CadFun;
update CadFun set Filhos=1 where CodFun=12;

alter table products drop foreign key products_ibfk_1;

load data infile 'E:\!UTA(Pratica)\BD\PraticaSQL' table products fields terminated by ',' enclosed by '"' lines terminated by '\n' ignore 1 lines;