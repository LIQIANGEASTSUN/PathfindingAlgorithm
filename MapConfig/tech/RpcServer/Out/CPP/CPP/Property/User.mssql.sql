create table [User]
(
	uid bigint not null default 0 check (uid>0),
	name varchar(64) not null,
	mtime int not null default 0,
	pwd varchar(32),
	index mtime(mtime),
	unique(name),
	primary key(uid)
);
