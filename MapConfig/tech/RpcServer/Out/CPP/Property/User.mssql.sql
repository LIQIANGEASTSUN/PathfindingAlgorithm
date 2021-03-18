create table [User]
(
	uid bigint not null default 0 check (uid>0),
	name varchar(64) not null,
	mtime int not null default 0,
	pwd varchar(32),
	mmr float(8) default 0,
	status tinyint default 0,
	lv int default 0,
	exp int default 0,
	continueWinActNum int default 0,
	continueLoseActNum int default 0,
	allActNum int default 0,
	nickName varchar(64),
	headIcon tinyint default 0,
	gold int default 0,
	diamond int default 0,
	channel int default 0,
	index mtime(mtime),
	unique(name),
	primary key(uid)
);
