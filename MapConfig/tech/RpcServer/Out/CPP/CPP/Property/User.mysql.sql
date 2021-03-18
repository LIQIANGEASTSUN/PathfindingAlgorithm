create table user
(
	uid bigint unsigned not null default 0,
	name varchar(64) not null,
	mtime int not null default 0,
	pwd varchar(32),
	key(mtime),
	unique key(name),
	primary key(uid)
)ENGINE=MYISAM DEFAULT CHARSET=utf8mb4;
