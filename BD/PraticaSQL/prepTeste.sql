create database prepTeste;
use prepTeste;

create table user(
	user_id int not null auto_increment primary key,
    username varchar(40),
    u_password varchar(255),
    email varchar(255)
);

create table roles(
	role_id int not null auto_increment primary key,
    role_name varchar(50)
);

create table user_roles(
	user_id int not null,
    role_id int not null,
	
    foreign key(user_id) references user(user_id),
    foreign key(role_id) references roles(role_id)
);