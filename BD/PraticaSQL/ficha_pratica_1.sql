create database Biblioteca;
drop database Biblioteca;
use Biblioteca;

/*CRIACAO DE TABELAS*/
create table Autores(
id_autor int not null primary key auto_increment,
nome varchar(100),
nacionalidade varchar(50)
);

insert into Autores(id_autor,nome,nacionalidade)values(default,'Jose Saramago','Portugal'),(default,'J.K Rowling','Reino Unido'),(default,'George Oswell','Reino Unido');
select * from Autores;

create table Editores(
id_editor int not null primary key auto_increment,
nome varchar(100),
pais varchar(50)
);

insert into Editores(id_editor,nome,pais)values(default,'Porto Editora','Portugal'),(default,'Bloomsbury','Reino Unido');
select * from Editores;

create table Livros(
id_livro int not null primary key auto_increment,
titulo varchar(100),
autor varchar(100),
editora varchar(100),
ano_publicacao int not null,

id_autor int,
id_editor int,
foreign key(id_autor) references Autores(id_autor),
foreign key(id_editor) references Editores(id_editor)
);

insert into Livros(titulo,autor,editora,ano_publicacao)values('Ensaio sobre a Cegueira','Saramago','Porto Editora',1995),('Harry Potter e Pedra Filosofal','Rowling','Bloombury',1997),('Memorial do Convento','Saramago','Bloomsbury',1949);
select * from Livros;

create table Leitores(
id_leitor int not null primary key auto_increment,
nome varchar(100),
data_nascimento date,
email varchar(100)
);

insert into Leitores(nome,data_nascimento,email)values("Ana Martins","2000-05-12","ana.martins@example.com"),("Carlos Silva","1998-11-23","carlos.silva@example.com");
select * from Leitores;

create table Emprestimo(
id_emprestimo int not null primary key auto_increment,
id_leitor int not null,
data_emprestimo date,
data_devolucao date not null
);


/*CONSULTAS*/
/*1*/
select count(autor) as Numero_de_Livro_por_Autor from Livros;

/*2*/
select count(nacionalidade) as Numero_de_Autores_por_Nacionalidade from autores;

/*3*/
select count(*) as Numero_de_Emprestimos from emprestimo group by data_emprestimo;

/*4*/
select count(*) as Numero_de_Livros_por_Titulos from livros group by titulo;

/*5*/
select count(*) from aut