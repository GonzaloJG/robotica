//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.6
//
// <auto-generated>
//
// Generated from file `CommonBehavior.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#include <CommonBehavior.h>
#include <IceUtil/PushDisableWarnings.h>
#include <Ice/LocalException.h>
#include <Ice/ValueFactory.h>
#include <Ice/OutgoingAsync.h>
#include <Ice/InputStream.h>
#include <Ice/OutputStream.h>
#include <IceUtil/PopDisableWarnings.h>

#if defined(_MSC_VER)
#   pragma warning(disable:4458) // declaration of ... hides class member
#elif defined(__clang__)
#   pragma clang diagnostic ignored "-Wshadow"
#elif defined(__GNUC__)
#   pragma GCC diagnostic ignored "-Wshadow"
#endif

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION / 100 != 307
#       error Ice version mismatch!
#   endif
#   if ICE_INT_VERSION % 100 >= 50
#       error Beta header file detected
#   endif
#   if ICE_INT_VERSION % 100 < 6
#       error Ice patch level mismatch!
#   endif
#endif

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace
{

    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_ids[2] =
            {
                    "::Ice::Object",
                    "::RoboCompCommonBehavior::CommonBehavior"
            };
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_ops[] =
            {
                    "getParameterList",
                    "getPeriod",
                    "getState",
                    "ice_id",
                    "ice_ids",
                    "ice_isA",
                    "ice_ping",
                    "killYourSelf",
                    "reloadConfig",
                    "setParameterList",
                    "setPeriod",
                    "timeAwake"
            };
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name = "getParameterList";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name = "getPeriod";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_getState_name = "getState";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name = "killYourSelf";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name = "reloadConfig";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name = "setParameterList";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name = "setPeriod";
    const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name = "timeAwake";

}

bool
RoboCompCommonBehavior::CommonBehavior::ice_isA(::std::string s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompCommonBehavior_CommonBehavior_ids, iceC_RoboCompCommonBehavior_CommonBehavior_ids + 2, s);
}

::std::vector<::std::string>
RoboCompCommonBehavior::CommonBehavior::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector<::std::string>(&iceC_RoboCompCommonBehavior_CommonBehavior_ids[0], &iceC_RoboCompCommonBehavior_CommonBehavior_ids[2]);
}

::std::string
RoboCompCommonBehavior::CommonBehavior::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompCommonBehavior::CommonBehavior::ice_staticId()
{
    static const ::std::string typeId = "::RoboCompCommonBehavior::CommonBehavior";
    return typeId;
}

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_getParameterList(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    inS.readEmptyParams();
    ParameterList ret = this->getParameterList(current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_getPeriod(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Idempotent, current.mode);
    inS.readEmptyParams();
    int ret = this->getPeriod(current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_getState(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    inS.readEmptyParams();
    State ret = this->getState(current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_killYourSelf(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    inS.readEmptyParams();
    this->killYourSelf(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_reloadConfig(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    inS.readEmptyParams();
    this->reloadConfig(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_setParameterList(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    ParameterList iceP_l;
    istr->readAll(iceP_l);
    inS.endReadParams();
    this->setParameterList(::std::move(iceP_l), current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_setPeriod(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Normal, current.mode);
    auto istr = inS.startReadParams();
    int iceP_period;
    istr->readAll(iceP_period);
    inS.endReadParams();
    this->setPeriod(iceP_period, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_timeAwake(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::OperationMode::Idempotent, current.mode);
    inS.readEmptyParams();
    int ret = this->timeAwake(current);
    auto ostr = inS.startWriteParams();
    ostr->writeAll(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompCommonBehavior_CommonBehavior_ops, iceC_RoboCompCommonBehavior_CommonBehavior_ops + 12, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompCommonBehavior_CommonBehavior_ops)
    {
        case 0:
        {
            return _iceD_getParameterList(in, current);
        }
        case 1:
        {
            return _iceD_getPeriod(in, current);
        }
        case 2:
        {
            return _iceD_getState(in, current);
        }
        case 3:
        {
            return _iceD_ice_id(in, current);
        }
        case 4:
        {
            return _iceD_ice_ids(in, current);
        }
        case 5:
        {
            return _iceD_ice_isA(in, current);
        }
        case 6:
        {
            return _iceD_ice_ping(in, current);
        }
        case 7:
        {
            return _iceD_killYourSelf(in, current);
        }
        case 8:
        {
            return _iceD_reloadConfig(in, current);
        }
        case 9:
        {
            return _iceD_setParameterList(in, current);
        }
        case 10:
        {
            return _iceD_setPeriod(in, current);
        }
        case 11:
        {
            return _iceD_timeAwake(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_getParameterList(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompCommonBehavior::ParameterList>>& outAsync, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name);
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
                     nullptr,
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_getPeriod(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<int>>& outAsync, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name);
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name, ::Ice::OperationMode::Idempotent, ::Ice::FormatType::DefaultFormat, context,
                     nullptr,
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_getState(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<::RoboCompCommonBehavior::State>>& outAsync, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_getState_name);
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_getState_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
                     nullptr,
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_killYourSelf(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
                     nullptr,
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_reloadConfig(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
                     nullptr,
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_setParameterList(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, const ParameterList& iceP_l, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
                     [&](::Ice::OutputStream* ostr)
                     {
                         ostr->writeAll(iceP_l);
                     },
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_setPeriod(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<void>>& outAsync, int iceP_period, const ::Ice::Context& context)
{
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name, ::Ice::OperationMode::Normal, ::Ice::FormatType::DefaultFormat, context,
                     [&](::Ice::OutputStream* ostr)
                     {
                         ostr->writeAll(iceP_period);
                     },
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::CommonBehaviorPrx::_iceI_timeAwake(const ::std::shared_ptr<::IceInternal::OutgoingAsyncT<int>>& outAsync, const ::Ice::Context& context)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name);
    outAsync->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name, ::Ice::OperationMode::Idempotent, ::Ice::FormatType::DefaultFormat, context,
                     nullptr,
                     nullptr);
}
/// \endcond

/// \cond INTERNAL
::std::shared_ptr<::Ice::ObjectPrx>
RoboCompCommonBehavior::CommonBehaviorPrx::_newInstance() const
{
    return ::IceInternal::createProxy<CommonBehaviorPrx>();
}
/// \endcond

const ::std::string&
RoboCompCommonBehavior::CommonBehaviorPrx::ice_staticId()
{
    return CommonBehavior::ice_staticId();
}

namespace Ice
{
}

#else // C++98 mapping

namespace
{

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name = "getParameterList";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name = "getPeriod";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_getState_name = "getState";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name = "killYourSelf";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name = "reloadConfig";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name = "setParameterList";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name = "setPeriod";

const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name = "timeAwake";

}

/// \cond INTERNAL
::IceProxy::Ice::Object* ::IceProxy::RoboCompCommonBehavior::upCast(CommonBehavior* p) { return p; }

void
::IceProxy::RoboCompCommonBehavior::_readProxy(::Ice::InputStream* istr, ::IceInternal::ProxyHandle< CommonBehavior>& v)
{
    ::Ice::ObjectPrx proxy;
    istr->read(proxy);
    if(!proxy)
    {
        v = 0;
    }
    else
    {
        v = new CommonBehavior;
        v->_copyFrom(proxy);
    }
}
/// \endcond

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_getParameterList(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name, ::Ice::Normal, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::RoboCompCommonBehavior::ParameterList
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_getParameterList(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCommonBehavior_CommonBehavior_getParameterList_name);
    ::RoboCompCommonBehavior::ParameterList ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_getPeriod(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name, ::Ice::Idempotent, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::Ice::Int
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_getPeriod(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCommonBehavior_CommonBehavior_getPeriod_name);
    ::Ice::Int ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_getState(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_getState_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_getState_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_getState_name, ::Ice::Normal, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_getState_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::RoboCompCommonBehavior::State
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_getState(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCommonBehavior_CommonBehavior_getState_name);
    ::RoboCompCommonBehavior::State ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_killYourSelf(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name, ::Ice::Normal, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_killYourSelf(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompCommonBehavior_CommonBehavior_killYourSelf_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_reloadConfig(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name, ::Ice::Normal, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_reloadConfig(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompCommonBehavior_CommonBehavior_reloadConfig_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_setParameterList(const ::RoboCompCommonBehavior::ParameterList& iceP_l, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_l);
        result->endWriteParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_setParameterList(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompCommonBehavior_CommonBehavior_setParameterList_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_setPeriod(::Ice::Int iceP_period, const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name, ::Ice::Normal, context);
        ::Ice::OutputStream* ostr = result->startWriteParams(::Ice::DefaultFormat);
        ostr->write(iceP_period);
        result->endWriteParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

void
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_setPeriod(const ::Ice::AsyncResultPtr& result)
{
    _end(result, iceC_RoboCompCommonBehavior_CommonBehavior_setPeriod_name);
}

::Ice::AsyncResultPtr
IceProxy::RoboCompCommonBehavior::CommonBehavior::_iceI_begin_timeAwake(const ::Ice::Context& context, const ::IceInternal::CallbackBasePtr& del, const ::Ice::LocalObjectPtr& cookie, bool sync)
{
    _checkTwowayOnly(iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name, sync);
    ::IceInternal::OutgoingAsyncPtr result = new ::IceInternal::CallbackOutgoing(this, iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name, del, cookie, sync);
    try
    {
        result->prepare(iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name, ::Ice::Idempotent, context);
        result->writeEmptyParams();
        result->invoke(iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name);
    }
    catch(const ::Ice::Exception& ex)
    {
        result->abort(ex);
    }
    return result;
}

::Ice::Int
IceProxy::RoboCompCommonBehavior::CommonBehavior::end_timeAwake(const ::Ice::AsyncResultPtr& result)
{
    ::Ice::AsyncResult::_check(result, this, iceC_RoboCompCommonBehavior_CommonBehavior_timeAwake_name);
    ::Ice::Int ret;
    if(!result->_waitForResponse())
    {
        try
        {
            result->_throwUserException();
        }
        catch(const ::Ice::UserException& ex)
        {
            throw ::Ice::UnknownUserException(__FILE__, __LINE__, ex.ice_id());
        }
    }
    ::Ice::InputStream* istr = result->_startReadParams();
    istr->read(ret);
    result->_endReadParams();
    return ret;
}

/// \cond INTERNAL
::IceProxy::Ice::Object*
IceProxy::RoboCompCommonBehavior::CommonBehavior::_newInstance() const
{
    return new CommonBehavior;
}
/// \endcond

const ::std::string&
IceProxy::RoboCompCommonBehavior::CommonBehavior::ice_staticId()
{
    return ::RoboCompCommonBehavior::CommonBehavior::ice_staticId();
}

RoboCompCommonBehavior::CommonBehavior::~CommonBehavior()
{
}

/// \cond INTERNAL
::Ice::Object* RoboCompCommonBehavior::upCast(CommonBehavior* p) { return p; }

/// \endcond

namespace
{
const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_ids[2] =
{
    "::Ice::Object",
    "::RoboCompCommonBehavior::CommonBehavior"
};

}

bool
RoboCompCommonBehavior::CommonBehavior::ice_isA(const ::std::string& s, const ::Ice::Current&) const
{
    return ::std::binary_search(iceC_RoboCompCommonBehavior_CommonBehavior_ids, iceC_RoboCompCommonBehavior_CommonBehavior_ids + 2, s);
}

::std::vector< ::std::string>
RoboCompCommonBehavior::CommonBehavior::ice_ids(const ::Ice::Current&) const
{
    return ::std::vector< ::std::string>(&iceC_RoboCompCommonBehavior_CommonBehavior_ids[0], &iceC_RoboCompCommonBehavior_CommonBehavior_ids[2]);
}

const ::std::string&
RoboCompCommonBehavior::CommonBehavior::ice_id(const ::Ice::Current&) const
{
    return ice_staticId();
}

const ::std::string&
RoboCompCommonBehavior::CommonBehavior::ice_staticId()
{
#ifdef ICE_HAS_THREAD_SAFE_LOCAL_STATIC
    static const ::std::string typeId = "::RoboCompCommonBehavior::CommonBehavior";
    return typeId;
#else
    return iceC_RoboCompCommonBehavior_CommonBehavior_ids[1];
#endif
}

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_getParameterList(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    inS.readEmptyParams();
    ParameterList ret = this->getParameterList(current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_getPeriod(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Idempotent, current.mode);
    inS.readEmptyParams();
    ::Ice::Int ret = this->getPeriod(current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_getState(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    inS.readEmptyParams();
    State ret = this->getState(current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_killYourSelf(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    inS.readEmptyParams();
    this->killYourSelf(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_reloadConfig(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    inS.readEmptyParams();
    this->reloadConfig(current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_setParameterList(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ParameterList iceP_l;
    istr->read(iceP_l);
    inS.endReadParams();
    this->setParameterList(iceP_l, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_setPeriod(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Normal, current.mode);
    ::Ice::InputStream* istr = inS.startReadParams();
    ::Ice::Int iceP_period;
    istr->read(iceP_period);
    inS.endReadParams();
    this->setPeriod(iceP_period, current);
    inS.writeEmptyParams();
    return true;
}
/// \endcond

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceD_timeAwake(::IceInternal::Incoming& inS, const ::Ice::Current& current)
{
    _iceCheckMode(::Ice::Idempotent, current.mode);
    inS.readEmptyParams();
    ::Ice::Int ret = this->timeAwake(current);
    ::Ice::OutputStream* ostr = inS.startWriteParams();
    ostr->write(ret);
    inS.endWriteParams();
    return true;
}
/// \endcond

namespace
{
const ::std::string iceC_RoboCompCommonBehavior_CommonBehavior_all[] =
{
    "getParameterList",
    "getPeriod",
    "getState",
    "ice_id",
    "ice_ids",
    "ice_isA",
    "ice_ping",
    "killYourSelf",
    "reloadConfig",
    "setParameterList",
    "setPeriod",
    "timeAwake"
};

}

/// \cond INTERNAL
bool
RoboCompCommonBehavior::CommonBehavior::_iceDispatch(::IceInternal::Incoming& in, const ::Ice::Current& current)
{
    ::std::pair<const ::std::string*, const ::std::string*> r = ::std::equal_range(iceC_RoboCompCommonBehavior_CommonBehavior_all, iceC_RoboCompCommonBehavior_CommonBehavior_all + 12, current.operation);
    if(r.first == r.second)
    {
        throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
    }

    switch(r.first - iceC_RoboCompCommonBehavior_CommonBehavior_all)
    {
        case 0:
        {
            return _iceD_getParameterList(in, current);
        }
        case 1:
        {
            return _iceD_getPeriod(in, current);
        }
        case 2:
        {
            return _iceD_getState(in, current);
        }
        case 3:
        {
            return _iceD_ice_id(in, current);
        }
        case 4:
        {
            return _iceD_ice_ids(in, current);
        }
        case 5:
        {
            return _iceD_ice_isA(in, current);
        }
        case 6:
        {
            return _iceD_ice_ping(in, current);
        }
        case 7:
        {
            return _iceD_killYourSelf(in, current);
        }
        case 8:
        {
            return _iceD_reloadConfig(in, current);
        }
        case 9:
        {
            return _iceD_setParameterList(in, current);
        }
        case 10:
        {
            return _iceD_setPeriod(in, current);
        }
        case 11:
        {
            return _iceD_timeAwake(in, current);
        }
        default:
        {
            assert(false);
            throw ::Ice::OperationNotExistException(__FILE__, __LINE__, current.id, current.facet, current.operation);
        }
    }
}
/// \endcond

/// \cond STREAM
void
RoboCompCommonBehavior::CommonBehavior::_iceWriteImpl(::Ice::OutputStream* ostr) const
{
    ostr->startSlice(ice_staticId(), -1, true);
    ::Ice::StreamWriter< CommonBehavior, ::Ice::OutputStream>::write(ostr, *this);
    ostr->endSlice();
}

void
RoboCompCommonBehavior::CommonBehavior::_iceReadImpl(::Ice::InputStream* istr)
{
    istr->startSlice();
    ::Ice::StreamReader< CommonBehavior, ::Ice::InputStream>::read(istr, *this);
    istr->endSlice();
}
/// \endcond

/// \cond INTERNAL
void
RoboCompCommonBehavior::_icePatchObjectPtr(CommonBehaviorPtr& handle, const ::Ice::ObjectPtr& v)
{
    handle = CommonBehaviorPtr::dynamicCast(v);
    if(v && !handle)
    {
        IceInternal::Ex::throwUOE(CommonBehavior::ice_staticId(), v);
    }
}
/// \endcond

namespace Ice
{
}

#endif