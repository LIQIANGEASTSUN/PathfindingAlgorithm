create table [Hero]
(
	mtime int not null default 0,
	id bigint not null default 0,
	activetime int default 0,
	uid bigint not null default 0,
	index mtime(mtime),
	index uid(uid),
	primary key(id)
);
