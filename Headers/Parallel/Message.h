#ifndef _PARALLEL_MESSAGE_H_
#define _PARALLEL_MESSAGE_H_

#include "Definitions.h"
#include "Transferable.h"

namespace Parallel {
class Message : public Parallel::Transferable {
 public:
  Message();
  Message(Int message);
  virtual ~Message();

  virtual void setMessage(Int message);
  virtual Int getMessage() const;

 protected:
  Int message;
};
}  // namespace Parallel

#endif  //#ifndef _PARALLEL_MESSGE_H_
