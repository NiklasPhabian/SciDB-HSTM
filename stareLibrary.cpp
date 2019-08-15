#include "stareLibrary.h"

#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "SpatialIndex.h"
#include "SpatialVector.h"
#include "SpatialInterface.h"
#include "TemporalIndex.h"

#include "HtmRangeIterator.h"
#include "BitShiftNameEncoding.h"
#include "EmbeddedLevelNameEncoding.h"


using namespace log4cxx;
using namespace log4cxx::helpers;

using namespace stare;
using namespace scidb;
using namespace boost::assign;

enum
  {
    STARE_ERROR1 = SCIDB_USER_ERROR_CODE_START
  };

STARE stareIndex;

static void stareFromLevelLatLon(const scidb::Value** args, scidb::Value* res, void* v) {
    int     iarg       = 0;
    float64 latDegrees = args[iarg++]->getDouble();
    float64 lonDegrees = args[iarg++]->getDouble();
    int64_t depth      = args[iarg++]->getInt64();

    STARE_ArrayIndexSpatialValue id = stareIndex.ValueFromLatLonDegrees(latDegrees, lonDegrees, depth);
    *(STARE_ArrayIndexSpatialValue*)res->data() = id;
}

static void stareToString (const scidb::Value** args, scidb::Value* res, void* v) {
    STARE_ArrayIndexSpatialValue& id = *(STARE_ArrayIndexSpatialValue*)args[0]->data();
    LOG4CXX_INFO(stare::logger, "STARE idx: " <<id);
    res->setString(to_string(id));  
}


REGISTER_CONVERTER(stareType,string,EXPLICIT_CONVERSION_COST,stareToString);


vector<Type> _types;
EXPORTED_FUNCTION const vector<Type>& GetTypes() {
  return _types;
}

vector<FunctionDescription> _functionDescs;
EXPORTED_FUNCTION const vector<FunctionDescription>& GetFunctions() {
  return _functionDescs;
}


static class stareLibrary {
public:
  stareLibrary() {

    // BasicConfigurator::configure();
    LOG4CXX_INFO(stare::logger, "Entering constructor.");

    Type stareType("stare",sizeof(STARE)*8); // size in bits
    _types.push_back(stareType);
    _functionDescs.push_back(FunctionDescription("stareFromLevelLatLon",
                                                list_of(TID_DOUBLE)(TID_DOUBLE)(TID_INT64),
                                                TypeId("int64"),
                                                &stareFromLevelLatLon));

    _errors[STARE_ERROR1] = "STARE construction error.";
    scidb::ErrorsLibrary::getInstance()->registerErrors("stare",&_errors);
  }

  ~stareLibrary() {
    scidb::ErrorsLibrary::getInstance()->unregisterErrors("stare");
  }

  private:
  scidb::ErrorsLibrary::ErrorsMessages _errors;

} _instance;


