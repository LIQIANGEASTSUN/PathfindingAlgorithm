create table [Online]
(
	uid bigint not null default 0,
	name varchar(64) not null,
	nodeId int default 0,
	gateName varchar(32),
	primary key(uid)
);
