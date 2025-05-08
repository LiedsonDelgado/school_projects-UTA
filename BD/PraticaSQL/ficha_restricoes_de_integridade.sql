/*Exercicio 1*/
create database ClientesDB;
use ClientesDB;

/*1.1*/
create table clientes(
	id_cliente int primary key not null auto_increment,
	nome varchar(256) not null,
	email varchar(256) unique,
    idade int check(idade>=18)
);
/*1.2*/
insert into clientes(id_clientes,nome,email,idade)values('Liedson Delgado','liedsondelgado38@gmail.com',17); /*erro ao introduzir valor de idade que nao corresponde a condicao >= 18*/

/*1.3*/
create table pedidos(
	id_pedido int primary key not null auto_increment,
    data_pedido date,
    id_cliente int,
    foreign key(id_cliente) references clientes(id_cliente)
);

/*1.4*/
insert into clientes values(1,'Liedson Delgado','liedsondelgado38@gmail.com',19);
insert into pedidos values(1,"2025-08-06",1);

/*1.5*/
delete from cliente where id_cliente = 1; /*nao deixa excluir pois existe um FK de outra tabela associada*/

/*1.6*/
create table produto(
	id_produto int not null auto_increment primary key,
    nome varchar(256) not null,
    preco decimal(10,2) not null default 0.00,
    quantidade int default 1
);

/*1.7*/
insert into produto(nome) value ('iPhone 11');
select * from produto; /*exibe o valores nao inseridos com valores padrao*/

/*1.8*/
create table departamento(
	id_dep int not null auto_increment primary key,
    nome varchar(256) not null
);

create table funcionario(
	id_func int not null auto_increment primary key,
    nome varchar(256) not null,
    id_dep int,
    foreign key(id_dep) references departamento(id_dep)
);

insert into departamento(nome) values('LEIT');
insert into funcionario(nome,id_dep) values('Liedson Delgado',1);

delete from departamento where id_dep = 1; /*nao deixa excluir pois existe um FK de outra tabela associada*/

/*Exercicio 2*/
create table pagamento(
	id_pagamento int not null auto_increment primary key,
    metodo varchar(256) not null check(metodo in('dinheiro','cartao','transferencia')),
    valor decimal(10,2) not null check(valor > 0)
);

insert into pagamento(metodo,valor) values ('cheque',-10); /*os dados inseridos nao respeitam as condicoes impostas*/

/*Exercicio 3*/
create table fornecedores(
    id_fornecedor int not null auto_increment primary key,
    nome varchar(256) not null,
    contacto varchar(100)
);

insert into fornecedores (nome, contacto) values ('Liedson Delgado', '9322743');

create table fornecimentos(
	id_fornecimento int primary key,
    id_produto int not null,
    id_fornecedor int not null,
    unique(id_produto,id_fornecimento),
    foreign key (id_fornecedor) references fornecedores(id_fornecedor),
    foreign key (id_produto) references produto(id_produto)
);

insert into fornecimentos (id_fornecimento,id_produto,id_fornecedor) value (1, 1,4500); /*Nao deixa atualizar a FK*/

/*Exercicio 4*/
create table avaliacoes(
	id_avaliacao int not null auto_increment primary key,
    comentario text,
     pontuacao int default 3 check (pontuacao between 1 and 5)
);

insert into avaliacoes(comentario) values ('Bom Trabalho');
insert into avaliacoes(comentario,pontuacao) values ('Muito Bom',6);/*erro ao inserir pontuacao que nao esteje no intervalo [1,5]*/