#ifndef INCLUDE_stareLibrary_H_
#define INCLUDE_stareLibrary_H_

#include "STARE.h"

#include "log4cxx/logger.h"
#include "log4cxx/basicconfigurator.h"
#include "log4cxx/helpers/exception.h"

#include <boost/assign.hpp>

#include "query/FunctionLibrary.h"
#include "query/FunctionDescription.h"
#include "query/TypeSystem.h"
#include "query/PhysicalOperator.h"

#include "system/ErrorsLibrary.h"

#include "SciDBAPI.h"


using namespace log4cxx;
using namespace log4cxx::helpers;

namespace stare {
  static LoggerPtr logger(Logger::getLogger("stare"));

  // Spatial
  static void stareFromResolutionLatLon(const scidb::Value** args, scidb::Value* res, void* v);
  static void latLonFromStare(const scidb::Value** args, scidb::Value* res, void* v);
  static void resolutionFromStare(const scidb::Value** args, scidb::Value* res, void* v);

  // Temporal
  static void stareFromUTCDateTime(const scidb::Value** args, scidb::Value* res, void* v);
  static void datetimeFromStare(const scidb::Value** args, scidb::Value* res, void* v);
  static void convDateTime2TimeT(const scidb::Value** args, scidb::Value* res, void*);

  // Converters
  static void spatialIndexValueToString(const scidb::Value** args, scidb::Value* res, void* v);
  static void spatialIndexValueToInt64(const scidb::Value** args, scidb::Value* res, void* v);
  static void temporalIndexValueToString(const scidb::Value** args, scidb::Value* res, void* v);
  static void LatLonDegreesToString(const scidb::Value** args, scidb::Value* res, void* v);

/*
void symbolFromHstm (const Value** arg, Value* res, void* v);
void hstmIntersect (const Value** arg, Value* res, void* v);
void hstmContains (const Value** arg, Value* res, void* v);
void hstmMergeRange (const Value** arg, Value* res, void* v);
void hstmAddRange (const Value** arg, Value* res, void* v);
void hstmNRanges (const Value** arg, Value* res, void* v);
void hstmLeftJustifiedNoLevel (const Value** arg, Value* res, void* v);
void hstmRightJustifiedNoLevel (const Value** arg, Value* res, void* v);
void hstmLevel (const Value** arg, Value* res, void* v);
void hstmLT (const Value** arg, Value* res, void* v);
void hstmGT (const Value** arg, Value* res, void* v);
void hstmEQ (const Value** arg, Value* res, void* v);
void hstmNE (const Value** arg, Value* res, void* v);
void hstmEqualToLevel (const Value** arg, Value* res, void* v);
*/

} /* namespace hstm */



#endif /* INCLUDE_stareLibrary_H_ */
