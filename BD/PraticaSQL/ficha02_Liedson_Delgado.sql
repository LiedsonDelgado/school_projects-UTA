/*Liedson Delgado-LEIT*/

/*Exercicio 1*/
create database loja_computadores;fabricante
use loja_computadores;

create table produtos(Codigo int not null,Nome varchar(250),Preco decimal(10,0),Fabricante int);
create table fabricante(Codigo int not null,Nome varchar(250));

/*Exercicio 2*/
insert into fabricante (Codigo,Nome) values (1,'Sony'),(2,'Creative Labs'),(3,'Hewlett-Packard'),(4,'Iomega'),(5,'Fujitsu'),(6,'Winchester');
insert into produtos (Codigo,Nome,Preco,Fabricante) values (1,'Hard Drive',240.00,5),(2,'Memory',120.00,6),(3,'Zip drive',150.00,4),(4,'Floppy disk',4.00,6),(5,'Monitor',240.00,1),(6,'DVD drive',180.00,2),(7,'CD drive',90.00,2),(8,'Printer',270.00,3),(9,'Toner cartridge',66.00,3),(10,'DVD burner',180.00,2);

/*Exercicio 3*/
select Nome from produtos;

/*Exercicio 4*/
select Nome,Preco from produtos;

/*Exercicio 5*/
select Nome,Preco from produtos order by Preco asc limit 1;

/*Exercicio 6*/
select Nome from produtos where Preco<=200;

/*Exercicio 7*/
select * from produtos where Preco>=60 and Preco<=120;

/*Exercicio 8*/
select * from produtos where Nome like '%drive%';

/*Exercicio 9*/
select * from produtos where Nome like '%r';

/*Exercicio 10*/
update produtos set Nome = 'Impressora Lazer' where Codigo = 8;

/*Exercicio 11*/
update produtos set Preco=Preco * 0.10;

/*Exercicio 12*/
update produtos set Preco=Preco * 0.10 where Preco >=120;
