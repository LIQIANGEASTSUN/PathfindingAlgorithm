// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: PropertyCliRpc.proto

#ifndef PROTOBUF_PropertyCliRpc_2eproto__INCLUDED
#define PROTOBUF_PropertyCliRpc_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2005000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2005000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "PublicStruct.pb.h"
// @@protoc_insertion_point(includes)

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_PropertyCliRpc_2eproto();
void protobuf_AssignDesc_PropertyCliRpc_2eproto();
void protobuf_ShutdownFile_PropertyCliRpc_2eproto();

class PropertyRpcSyncAsk;
class PropertyRpcSyncReply;
class PropertyRpcUpdateNotify;
class PropertyRpcChangeHeadAsk;
class PropertyRpcChangeHeadReply;

// ===================================================================

class PropertyRpcSyncAsk : public ::google::protobuf::Message {
 public:
  PropertyRpcSyncAsk();
  virtual ~PropertyRpcSyncAsk();

  PropertyRpcSyncAsk(const PropertyRpcSyncAsk& from);

  inline PropertyRpcSyncAsk& operator=(const PropertyRpcSyncAsk& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PropertyRpcSyncAsk& default_instance();

  void Swap(PropertyRpcSyncAsk* other);

  // implements Message ----------------------------------------------

  PropertyRpcSyncAsk* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PropertyRpcSyncAsk& from);
  void MergeFrom(const PropertyRpcSyncAsk& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint64 Uid = 1 [default = -1];
  inline bool has_uid() const;
  inline void clear_uid();
  static const int kUidFieldNumber = 1;
  inline ::google::protobuf::int64 uid() const;
  inline void set_uid(::google::protobuf::int64 value);

  // @@protoc_insertion_point(class_scope:PropertyRpcSyncAsk)
 private:
  inline void set_has_uid();
  inline void clear_has_uid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 uid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_PropertyCliRpc_2eproto();
  friend void protobuf_AssignDesc_PropertyCliRpc_2eproto();
  friend void protobuf_ShutdownFile_PropertyCliRpc_2eproto();

  void InitAsDefaultInstance();
  static PropertyRpcSyncAsk* default_instance_;
};
// -------------------------------------------------------------------

class PropertyRpcSyncReply : public ::google::protobuf::Message {
 public:
  PropertyRpcSyncReply();
  virtual ~PropertyRpcSyncReply();

  PropertyRpcSyncReply(const PropertyRpcSyncReply& from);

  inline PropertyRpcSyncReply& operator=(const PropertyRpcSyncReply& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PropertyRpcSyncReply& default_instance();

  void Swap(PropertyRpcSyncReply* other);

  // implements Message ----------------------------------------------

  PropertyRpcSyncReply* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PropertyRpcSyncReply& from);
  void MergeFrom(const PropertyRpcSyncReply& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 Result = 1 [default = -9999];
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // optional .User User = 2;
  inline bool has_user() const;
  inline void clear_user();
  static const int kUserFieldNumber = 2;
  inline const ::User& user() const;
  inline ::User* mutable_user();
  inline ::User* release_user();
  inline void set_allocated_user(::User* user);

  // @@protoc_insertion_point(class_scope:PropertyRpcSyncReply)
 private:
  inline void set_has_result();
  inline void clear_has_result();
  inline void set_has_user();
  inline void clear_has_user();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::User* user_;
  ::google::protobuf::int32 result_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_PropertyCliRpc_2eproto();
  friend void protobuf_AssignDesc_PropertyCliRpc_2eproto();
  friend void protobuf_ShutdownFile_PropertyCliRpc_2eproto();

  void InitAsDefaultInstance();
  static PropertyRpcSyncReply* default_instance_;
};
// -------------------------------------------------------------------

class PropertyRpcUpdateNotify : public ::google::protobuf::Message {
 public:
  PropertyRpcUpdateNotify();
  virtual ~PropertyRpcUpdateNotify();

  PropertyRpcUpdateNotify(const PropertyRpcUpdateNotify& from);

  inline PropertyRpcUpdateNotify& operator=(const PropertyRpcUpdateNotify& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PropertyRpcUpdateNotify& default_instance();

  void Swap(PropertyRpcUpdateNotify* other);

  // implements Message ----------------------------------------------

  PropertyRpcUpdateNotify* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PropertyRpcUpdateNotify& from);
  void MergeFrom(const PropertyRpcUpdateNotify& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional .User User = 1;
  inline bool has_user() const;
  inline void clear_user();
  static const int kUserFieldNumber = 1;
  inline const ::User& user() const;
  inline ::User* mutable_user();
  inline ::User* release_user();
  inline void set_allocated_user(::User* user);

  // @@protoc_insertion_point(class_scope:PropertyRpcUpdateNotify)
 private:
  inline void set_has_user();
  inline void clear_has_user();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::User* user_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_PropertyCliRpc_2eproto();
  friend void protobuf_AssignDesc_PropertyCliRpc_2eproto();
  friend void protobuf_ShutdownFile_PropertyCliRpc_2eproto();

  void InitAsDefaultInstance();
  static PropertyRpcUpdateNotify* default_instance_;
};
// -------------------------------------------------------------------

class PropertyRpcChangeHeadAsk : public ::google::protobuf::Message {
 public:
  PropertyRpcChangeHeadAsk();
  virtual ~PropertyRpcChangeHeadAsk();

  PropertyRpcChangeHeadAsk(const PropertyRpcChangeHeadAsk& from);

  inline PropertyRpcChangeHeadAsk& operator=(const PropertyRpcChangeHeadAsk& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PropertyRpcChangeHeadAsk& default_instance();

  void Swap(PropertyRpcChangeHeadAsk* other);

  // implements Message ----------------------------------------------

  PropertyRpcChangeHeadAsk* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PropertyRpcChangeHeadAsk& from);
  void MergeFrom(const PropertyRpcChangeHeadAsk& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 HeadID = 1 [default = 1];
  inline bool has_headid() const;
  inline void clear_headid();
  static const int kHeadIDFieldNumber = 1;
  inline ::google::protobuf::int32 headid() const;
  inline void set_headid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PropertyRpcChangeHeadAsk)
 private:
  inline void set_has_headid();
  inline void clear_has_headid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 headid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_PropertyCliRpc_2eproto();
  friend void protobuf_AssignDesc_PropertyCliRpc_2eproto();
  friend void protobuf_ShutdownFile_PropertyCliRpc_2eproto();

  void InitAsDefaultInstance();
  static PropertyRpcChangeHeadAsk* default_instance_;
};
// -------------------------------------------------------------------

class PropertyRpcChangeHeadReply : public ::google::protobuf::Message {
 public:
  PropertyRpcChangeHeadReply();
  virtual ~PropertyRpcChangeHeadReply();

  PropertyRpcChangeHeadReply(const PropertyRpcChangeHeadReply& from);

  inline PropertyRpcChangeHeadReply& operator=(const PropertyRpcChangeHeadReply& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PropertyRpcChangeHeadReply& default_instance();

  void Swap(PropertyRpcChangeHeadReply* other);

  // implements Message ----------------------------------------------

  PropertyRpcChangeHeadReply* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PropertyRpcChangeHeadReply& from);
  void MergeFrom(const PropertyRpcChangeHeadReply& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional sint32 Result = 1 [default = -9999];
  inline bool has_result() const;
  inline void clear_result();
  static const int kResultFieldNumber = 1;
  inline ::google::protobuf::int32 result() const;
  inline void set_result(::google::protobuf::int32 value);

  // optional sint32 HeadID = 2 [default = 1];
  inline bool has_headid() const;
  inline void clear_headid();
  static const int kHeadIDFieldNumber = 2;
  inline ::google::protobuf::int32 headid() const;
  inline void set_headid(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:PropertyRpcChangeHeadReply)
 private:
  inline void set_has_result();
  inline void clear_has_result();
  inline void set_has_headid();
  inline void clear_has_headid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 result_;
  ::google::protobuf::int32 headid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(2 + 31) / 32];

  friend void  protobuf_AddDesc_PropertyCliRpc_2eproto();
  friend void protobuf_AssignDesc_PropertyCliRpc_2eproto();
  friend void protobuf_ShutdownFile_PropertyCliRpc_2eproto();

  void InitAsDefaultInstance();
  static PropertyRpcChangeHeadReply* default_instance_;
};
// ===================================================================


// ===================================================================

// PropertyRpcSyncAsk

// optional sint64 Uid = 1 [default = -1];
inline bool PropertyRpcSyncAsk::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PropertyRpcSyncAsk::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PropertyRpcSyncAsk::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PropertyRpcSyncAsk::clear_uid() {
  uid_ = GOOGLE_LONGLONG(-1);
  clear_has_uid();
}
inline ::google::protobuf::int64 PropertyRpcSyncAsk::uid() const {
  return uid_;
}
inline void PropertyRpcSyncAsk::set_uid(::google::protobuf::int64 value) {
  set_has_uid();
  uid_ = value;
}

// -------------------------------------------------------------------

// PropertyRpcSyncReply

// optional sint32 Result = 1 [default = -9999];
inline bool PropertyRpcSyncReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PropertyRpcSyncReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PropertyRpcSyncReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PropertyRpcSyncReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 PropertyRpcSyncReply::result() const {
  return result_;
}
inline void PropertyRpcSyncReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}

// optional .User User = 2;
inline bool PropertyRpcSyncReply::has_user() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PropertyRpcSyncReply::set_has_user() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PropertyRpcSyncReply::clear_has_user() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PropertyRpcSyncReply::clear_user() {
  if (user_ != NULL) user_->::User::Clear();
  clear_has_user();
}
inline const ::User& PropertyRpcSyncReply::user() const {
  return user_ != NULL ? *user_ : *default_instance_->user_;
}
inline ::User* PropertyRpcSyncReply::mutable_user() {
  set_has_user();
  if (user_ == NULL) user_ = new ::User;
  return user_;
}
inline ::User* PropertyRpcSyncReply::release_user() {
  clear_has_user();
  ::User* temp = user_;
  user_ = NULL;
  return temp;
}
inline void PropertyRpcSyncReply::set_allocated_user(::User* user) {
  delete user_;
  user_ = user;
  if (user) {
    set_has_user();
  } else {
    clear_has_user();
  }
}

// -------------------------------------------------------------------

// PropertyRpcUpdateNotify

// optional .User User = 1;
inline bool PropertyRpcUpdateNotify::has_user() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PropertyRpcUpdateNotify::set_has_user() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PropertyRpcUpdateNotify::clear_has_user() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PropertyRpcUpdateNotify::clear_user() {
  if (user_ != NULL) user_->::User::Clear();
  clear_has_user();
}
inline const ::User& PropertyRpcUpdateNotify::user() const {
  return user_ != NULL ? *user_ : *default_instance_->user_;
}
inline ::User* PropertyRpcUpdateNotify::mutable_user() {
  set_has_user();
  if (user_ == NULL) user_ = new ::User;
  return user_;
}
inline ::User* PropertyRpcUpdateNotify::release_user() {
  clear_has_user();
  ::User* temp = user_;
  user_ = NULL;
  return temp;
}
inline void PropertyRpcUpdateNotify::set_allocated_user(::User* user) {
  delete user_;
  user_ = user;
  if (user) {
    set_has_user();
  } else {
    clear_has_user();
  }
}

// -------------------------------------------------------------------

// PropertyRpcChangeHeadAsk

// optional sint32 HeadID = 1 [default = 1];
inline bool PropertyRpcChangeHeadAsk::has_headid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PropertyRpcChangeHeadAsk::set_has_headid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PropertyRpcChangeHeadAsk::clear_has_headid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PropertyRpcChangeHeadAsk::clear_headid() {
  headid_ = 1;
  clear_has_headid();
}
inline ::google::protobuf::int32 PropertyRpcChangeHeadAsk::headid() const {
  return headid_;
}
inline void PropertyRpcChangeHeadAsk::set_headid(::google::protobuf::int32 value) {
  set_has_headid();
  headid_ = value;
}

// -------------------------------------------------------------------

// PropertyRpcChangeHeadReply

// optional sint32 Result = 1 [default = -9999];
inline bool PropertyRpcChangeHeadReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PropertyRpcChangeHeadReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PropertyRpcChangeHeadReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PropertyRpcChangeHeadReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 PropertyRpcChangeHeadReply::result() const {
  return result_;
}
inline void PropertyRpcChangeHeadReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}

// optional sint32 HeadID = 2 [default = 1];
inline bool PropertyRpcChangeHeadReply::has_headid() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void PropertyRpcChangeHeadReply::set_has_headid() {
  _has_bits_[0] |= 0x00000002u;
}
inline void PropertyRpcChangeHeadReply::clear_has_headid() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void PropertyRpcChangeHeadReply::clear_headid() {
  headid_ = 1;
  clear_has_headid();
}
inline ::google::protobuf::int32 PropertyRpcChangeHeadReply::headid() const {
  return headid_;
}
inline void PropertyRpcChangeHeadReply::set_headid(::google::protobuf::int32 value) {
  set_has_headid();
  headid_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_PropertyCliRpc_2eproto__INCLUDED
