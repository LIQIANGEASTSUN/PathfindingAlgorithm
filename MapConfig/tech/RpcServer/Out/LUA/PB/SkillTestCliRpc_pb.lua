-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf"
local PublicStruct_pb = require("PublicStruct_pb")
module('SkillTestCliRpc_pb')


local SKILLTESTSKILLEVENTTEST = protobuf.Descriptor();
local SKILLTESTSKILLEVENTTEST_EVENTID_FIELD = protobuf.FieldDescriptor();
local SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD = protobuf.FieldDescriptor();
local SKILLTESTSKILLEVENTTEST_BULLETS_FIELD = protobuf.FieldDescriptor();
local SKILLTESTSKILLEVENTTEST_BULLET_FIELD = protobuf.FieldDescriptor();
local SKILLTESTBULLET = protobuf.Descriptor();
local SKILLTESTBULLET_ID_FIELD = protobuf.FieldDescriptor();
local SKILLTESTRPCSYNCNOTIFY = protobuf.Descriptor();

SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.name = "EventId"
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.full_name = ".SkillTestSkillEventTest.EventId"
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.number = 1
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.index = 0
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.label = 1
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.has_default_value = true
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.default_value = -1
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.type = 17
SKILLTESTSKILLEVENTTEST_EVENTID_FIELD.cpp_type = 1

SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.name = "SubEvents"
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.full_name = ".SkillTestSkillEventTest.SubEvents"
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.number = 2
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.index = 1
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.label = 3
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.has_default_value = false
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.default_value = {}
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.message_type = SKILLTESTBULLET
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.type = 11
SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD.cpp_type = 10

SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.name = "Bullets"
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.full_name = ".SkillTestSkillEventTest.Bullets"
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.number = 3
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.index = 2
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.label = 3
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.has_default_value = false
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.default_value = {}
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.message_type = SKILLTESTBULLET
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.type = 11
SKILLTESTSKILLEVENTTEST_BULLETS_FIELD.cpp_type = 10

SKILLTESTSKILLEVENTTEST_BULLET_FIELD.name = "Bullet"
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.full_name = ".SkillTestSkillEventTest.Bullet"
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.number = 4
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.index = 3
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.label = 1
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.has_default_value = false
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.default_value = nil
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.message_type = SKILLTESTBULLET
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.type = 11
SKILLTESTSKILLEVENTTEST_BULLET_FIELD.cpp_type = 10

SKILLTESTSKILLEVENTTEST.name = "SkillTestSkillEventTest"
SKILLTESTSKILLEVENTTEST.full_name = ".SkillTestSkillEventTest"
SKILLTESTSKILLEVENTTEST.nested_types = {}
SKILLTESTSKILLEVENTTEST.enum_types = {}
SKILLTESTSKILLEVENTTEST.fields = {SKILLTESTSKILLEVENTTEST_EVENTID_FIELD, SKILLTESTSKILLEVENTTEST_SUBEVENTS_FIELD, SKILLTESTSKILLEVENTTEST_BULLETS_FIELD, SKILLTESTSKILLEVENTTEST_BULLET_FIELD}
SKILLTESTSKILLEVENTTEST.is_extendable = false
SKILLTESTSKILLEVENTTEST.extensions = {}
SKILLTESTBULLET_ID_FIELD.name = "Id"
SKILLTESTBULLET_ID_FIELD.full_name = ".SkillTestBullet.Id"
SKILLTESTBULLET_ID_FIELD.number = 1
SKILLTESTBULLET_ID_FIELD.index = 0
SKILLTESTBULLET_ID_FIELD.label = 1
SKILLTESTBULLET_ID_FIELD.has_default_value = true
SKILLTESTBULLET_ID_FIELD.default_value = -1
SKILLTESTBULLET_ID_FIELD.type = 17
SKILLTESTBULLET_ID_FIELD.cpp_type = 1

SKILLTESTBULLET.name = "SkillTestBullet"
SKILLTESTBULLET.full_name = ".SkillTestBullet"
SKILLTESTBULLET.nested_types = {}
SKILLTESTBULLET.enum_types = {}
SKILLTESTBULLET.fields = {SKILLTESTBULLET_ID_FIELD}
SKILLTESTBULLET.is_extendable = false
SKILLTESTBULLET.extensions = {}
SKILLTESTRPCSYNCNOTIFY.name = "SkillTestRpcSyncNotify"
SKILLTESTRPCSYNCNOTIFY.full_name = ".SkillTestRpcSyncNotify"
SKILLTESTRPCSYNCNOTIFY.nested_types = {}
SKILLTESTRPCSYNCNOTIFY.enum_types = {}
SKILLTESTRPCSYNCNOTIFY.fields = {}
SKILLTESTRPCSYNCNOTIFY.is_extendable = false
SKILLTESTRPCSYNCNOTIFY.extensions = {}

SkillTestBullet = protobuf.Message(SKILLTESTBULLET)
SkillTestRpcSyncNotify = protobuf.Message(SKILLTESTRPCSYNCNOTIFY)
SkillTestSkillEventTest = protobuf.Message(SKILLTESTSKILLEVENTTEST)

