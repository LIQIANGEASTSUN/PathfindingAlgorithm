create table hero
(
	mtime int not null default 0,
	id bigint not null default 0,
	activetime int default 0,
	uid bigint not null default 0,
	key(mtime),
	key(uid),
	primary key(id)
)ENGINE=MYISAM DEFAULT CHARSET=utf8mb4;
