//===--- SILLocation.cpp - Location information for SIL nodes ---*- C++ -*-===//
//
// This source file is part of the Swift.org open source project
//
// Copyright (c) 2014 - 2015 Apple Inc. and the Swift project authors
// Licensed under Apache License v2.0 with Runtime Library Exception
//
// See http://swift.org/LICENSE.txt for license information
// See http://swift.org/CONTRIBUTORS.txt for the list of Swift project authors
//
//===----------------------------------------------------------------------===//

#include "swift/SIL/SILLocation.h"
#include "swift/AST/Decl.h"
#include "swift/AST/Expr.h"
#include "swift/AST/Stmt.h"

namespace swift {
SourceLoc getSourceLocForSILLocation(SILLocation loc) {
  if (auto decl = loc.dyn_cast<Decl*>()) {
    return decl->getLoc();
  }
  if (auto expr = loc.dyn_cast<Expr*>()) {
    return expr->getLoc();
  }
  if (auto stmt = loc.dyn_cast<Stmt*>()) {
    return stmt->getStartLoc();
  }
  llvm_unreachable("impossible SILLocation");
}

SourceLoc getStartSourceLocForSILLocation(SILLocation loc) {
  if (auto decl = loc.dyn_cast<Decl*>()) {
    return decl->getStartLoc();
  }
  if (auto expr = loc.dyn_cast<Expr*>()) {
    return expr->getStartLoc();
  }
  if (auto stmt = loc.dyn_cast<Stmt*>()) {
    return stmt->getStartLoc();
  }
  llvm_unreachable("impossible SILLocation");
}

SourceLoc getEndSourceLocForSILLocation(SILLocation loc) {
  if (auto decl = loc.dyn_cast<Decl*>()) {
    return decl->getEndLoc();
  }
  if (auto expr = loc.dyn_cast<Expr*>()) {
    return expr->getEndLoc();
  }
  if (auto stmt = loc.dyn_cast<Stmt*>()) {
    return stmt->getEndLoc();
  }
  llvm_unreachable("impossible SILLocation");
}
};
