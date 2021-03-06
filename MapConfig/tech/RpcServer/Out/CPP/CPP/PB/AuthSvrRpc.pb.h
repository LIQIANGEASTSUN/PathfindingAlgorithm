// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: AuthSvrRpc.proto

#ifndef PROTOBUF_AuthSvrRpc_2eproto__INCLUDED
#define PROTOBUF_AuthSvrRpc_2eproto__INCLUDED

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
void  protobuf_AddDesc_AuthSvrRpc_2eproto();
void protobuf_AssignDesc_AuthSvrRpc_2eproto();
void protobuf_ShutdownFile_AuthSvrRpc_2eproto();

class AuthRpcOfflineAsk;
class AuthRpcOfflineReply;

// ===================================================================

class AuthRpcOfflineAsk : public ::google::protobuf::Message {
 public:
  AuthRpcOfflineAsk();
  virtual ~AuthRpcOfflineAsk();

  AuthRpcOfflineAsk(const AuthRpcOfflineAsk& from);

  inline AuthRpcOfflineAsk& operator=(const AuthRpcOfflineAsk& from) {
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
  static const AuthRpcOfflineAsk& default_instance();

  void Swap(AuthRpcOfflineAsk* other);

  // implements Message ----------------------------------------------

  AuthRpcOfflineAsk* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AuthRpcOfflineAsk& from);
  void MergeFrom(const AuthRpcOfflineAsk& from);
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

  // @@protoc_insertion_point(class_scope:AuthRpcOfflineAsk)
 private:
  inline void set_has_uid();
  inline void clear_has_uid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int64 uid_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_AuthSvrRpc_2eproto();
  friend void protobuf_AssignDesc_AuthSvrRpc_2eproto();
  friend void protobuf_ShutdownFile_AuthSvrRpc_2eproto();

  void InitAsDefaultInstance();
  static AuthRpcOfflineAsk* default_instance_;
};
// -------------------------------------------------------------------

class AuthRpcOfflineReply : public ::google::protobuf::Message {
 public:
  AuthRpcOfflineReply();
  virtual ~AuthRpcOfflineReply();

  AuthRpcOfflineReply(const AuthRpcOfflineReply& from);

  inline AuthRpcOfflineReply& operator=(const AuthRpcOfflineReply& from) {
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
  static const AuthRpcOfflineReply& default_instance();

  void Swap(AuthRpcOfflineReply* other);

  // implements Message ----------------------------------------------

  AuthRpcOfflineReply* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const AuthRpcOfflineReply& from);
  void MergeFrom(const AuthRpcOfflineReply& from);
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

  // @@protoc_insertion_point(class_scope:AuthRpcOfflineReply)
 private:
  inline void set_has_result();
  inline void clear_has_result();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::int32 result_;

  mutable int _cached_size_;
  ::google::protobuf::uint32 _has_bits_[(1 + 31) / 32];

  friend void  protobuf_AddDesc_AuthSvrRpc_2eproto();
  friend void protobuf_AssignDesc_AuthSvrRpc_2eproto();
  friend void protobuf_ShutdownFile_AuthSvrRpc_2eproto();

  void InitAsDefaultInstance();
  static AuthRpcOfflineReply* default_instance_;
};
// ===================================================================


// ===================================================================

// AuthRpcOfflineAsk

// optional sint64 Uid = 1 [default = -1];
inline bool AuthRpcOfflineAsk::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AuthRpcOfflineAsk::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AuthRpcOfflineAsk::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AuthRpcOfflineAsk::clear_uid() {
  uid_ = GOOGLE_LONGLONG(-1);
  clear_has_uid();
}
inline ::google::protobuf::int64 AuthRpcOfflineAsk::uid() const {
  return uid_;
}
inline void AuthRpcOfflineAsk::set_uid(::google::protobuf::int64 value) {
  set_has_uid();
  uid_ = value;
}

// -------------------------------------------------------------------

// AuthRpcOfflineReply

// optional sint32 Result = 1 [default = -9999];
inline bool AuthRpcOfflineReply::has_result() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void AuthRpcOfflineReply::set_has_result() {
  _has_bits_[0] |= 0x00000001u;
}
inline void AuthRpcOfflineReply::clear_has_result() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void AuthRpcOfflineReply::clear_result() {
  result_ = -9999;
  clear_has_result();
}
inline ::google::protobuf::int32 AuthRpcOfflineReply::result() const {
  return result_;
}
inline void AuthRpcOfflineReply::set_result(::google::protobuf::int32 value) {
  set_has_result();
  result_ = value;
}


// @@protoc_insertion_point(namespace_scope)

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_AuthSvrRpc_2eproto__INCLUDED
