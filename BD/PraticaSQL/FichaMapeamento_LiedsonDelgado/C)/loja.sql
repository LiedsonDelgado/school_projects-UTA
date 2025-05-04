create database Loja;
use Loja;

create table Cliente(
id_cliente int primary key not null auto_increment,
nome varchar(250),
email varchar(250)
);

create table Pedido(
id_pedido int primary key auto_increment,
data_p date,
id_cliente int,
foreign key (id_cliente) references Cliente(id_cliente)
);