// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file has been auto-generated by code_generator_v8.py. DO NOT MODIFY!

#include "config.h"
#include "V8SpeechRecognitionEventInit.h"

#include "bindings/core/v8/ExceptionState.h"
#include "bindings/core/v8/V8EventInit.h"
#include "bindings/modules/v8/V8SpeechRecognitionResultList.h"

namespace blink {

void V8SpeechRecognitionEventInit::toImpl(v8::Isolate* isolate, v8::Local<v8::Value> v8Value, SpeechRecognitionEventInit& impl, ExceptionState& exceptionState)
{
    if (isUndefinedOrNull(v8Value))
        return;
    if (!v8Value->IsObject()) {
        exceptionState.throwTypeError("cannot convert to dictionary.");
        return;
    }

    V8EventInit::toImpl(isolate, v8Value, impl, exceptionState);
    if (exceptionState.hadException())
        return;

    v8::TryCatch block;
    v8::Local<v8::Object> v8Object;
    if (!v8Call(v8Value->ToObject(isolate->GetCurrentContext()), v8Object, block)) {
        exceptionState.rethrowV8Exception(block.Exception());
        return;
    }
    {
        v8::Local<v8::Value> resultIndexValue;
        if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "resultIndex")).ToLocal(&resultIndexValue)) {
            exceptionState.rethrowV8Exception(block.Exception());
            return;
        }
        if (resultIndexValue.IsEmpty() || resultIndexValue->IsUndefined()) {
            // Do nothing.
        } else {
            unsigned resultIndex = toUInt32(isolate, resultIndexValue, NormalConversion, exceptionState);
            if (exceptionState.hadException())
                return;
            impl.setResultIndex(resultIndex);
        }
    }

    {
        v8::Local<v8::Value> resultsValue;
        if (!v8Object->Get(isolate->GetCurrentContext(), v8String(isolate, "results")).ToLocal(&resultsValue)) {
            exceptionState.rethrowV8Exception(block.Exception());
            return;
        }
        if (resultsValue.IsEmpty() || resultsValue->IsUndefined()) {
            // Do nothing.
        } else {
            SpeechRecognitionResultList* results = V8SpeechRecognitionResultList::toImplWithTypeCheck(isolate, resultsValue);
            if (!results && !resultsValue->IsNull()) {
                exceptionState.throwTypeError("member results is not of type SpeechRecognitionResultList.");
                return;
            }
            impl.setResults(results);
        }
    }

}

v8::Local<v8::Value> toV8(const SpeechRecognitionEventInit& impl, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    v8::Local<v8::Object> v8Object = v8::Object::New(isolate);
    if (!toV8EventInit(impl, v8Object, creationContext, isolate))
        return v8::Local<v8::Value>();
    if (!toV8SpeechRecognitionEventInit(impl, v8Object, creationContext, isolate))
        return v8::Local<v8::Value>();
    return v8Object;
}

bool toV8SpeechRecognitionEventInit(const SpeechRecognitionEventInit& impl, v8::Local<v8::Object> dictionary, v8::Local<v8::Object> creationContext, v8::Isolate* isolate)
{
    if (impl.hasResultIndex()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "resultIndex"), v8::Integer::NewFromUnsigned(isolate, impl.resultIndex()))))
            return false;
    }

    if (impl.hasResults()) {
        if (!v8CallBoolean(dictionary->CreateDataProperty(isolate->GetCurrentContext(), v8String(isolate, "results"), toV8(impl.results(), creationContext, isolate))))
            return false;
    }

    return true;
}

SpeechRecognitionEventInit NativeValueTraits<SpeechRecognitionEventInit>::nativeValue(v8::Isolate* isolate, v8::Local<v8::Value> value, ExceptionState& exceptionState)
{
    SpeechRecognitionEventInit impl;
    V8SpeechRecognitionEventInit::toImpl(isolate, value, impl, exceptionState);
    return impl;
}

} // namespace blink
