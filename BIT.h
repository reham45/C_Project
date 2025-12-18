#ifndef _BIT_H_
#define  _BIT_H_

#define SET_BIT(var,bitno) (var|=(1<<bitno))
#define CLR_BIT(var,bitno) (var&=(~(1<<bitno)))
#define TOGGLE_BIT(var,bitno) (var^=(1<<bitno))
#define GET_BIT(var,bitno) ((var>>bitno)&1)

#endif
