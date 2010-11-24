//
//  TSDocFilter.h
//  TSDocDB
//
//  Created by Isaac Tewolde on 10-07-27.
//  Copyright 2010 Ticklespace.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#include "tcutil.h"
#include "tctdb.h"

typedef enum {
  eq,gt,lt,gte,lte,ne,beginsWith,endsWith,contains,anyword,phrase
} OpType;

typedef enum {
  matchAll, matchAny
} MatchType;

typedef enum {
  numericFilter, stringFilter
} FilterType;

@interface TSDocFilter : NSObject {
  NSString *colName;
  OpType op;
  NSMutableSet *valSet;
  MatchType matchType;
  FilterType filterType;
}

@property(nonatomic,retain) NSString *colName;
@property(nonatomic,readwrite) OpType op;
@property(nonatomic,readwrite) FilterType filterType;
@property(nonatomic,readwrite) MatchType matchType;

-(id)initStringFilter:(NSString *)columName withOp:(OpType)opType andVal:(id)val;
-(id)initNumericFilter:(NSString *)columName withOp:(OpType)opType andVal:(id)val;
-(NSString *)getVal;
-(NSArray *)getVals;
-(void)setVal:(id)val;
-(void)addToQuery:(TDBQRY *)qry;
-(NSString *)getFilterSig;
@end
