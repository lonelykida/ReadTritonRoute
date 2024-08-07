/* Authors: Lutong Wang and Bangqi Xu */
/*
 * Copyright (c) 2019, The Regents of the University of California
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the University nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE REGENTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef _FR_POINT_H_
#define _FR_POINT_H_

//√
#include "frBaseTypes.h"

namespace fr {
  class frTransform;

  //点的构造 - 保存每个点的x,y坐标
  class frPoint {
  public:
    // constructors
    //初始化xCoord和yCoord成员变量
    frPoint(): xCoord(0), yCoord(0) {}
    frPoint(const frPoint &tmpPoint): xCoord(tmpPoint.xCoord), yCoord(tmpPoint.yCoord) {}
    frPoint(const frCoord tmpX, const frCoord tmpY)
      : xCoord(tmpX), yCoord(tmpY) {};
    // setters
    void set(const frPoint &tmpPoint) {
      xCoord = tmpPoint.xCoord;
      yCoord = tmpPoint.yCoord;
    }
    void set(const frCoord tmpX, const frCoord tmpY) {
      xCoord = tmpX;
      yCoord = tmpY;
    }
    // getters
    frCoord x() const {
      return xCoord;
    }
    frCoord y() const {
      return yCoord;
    }
    // others
    void transform(const frTransform &xform);
    bool operator<(const frPoint &pIn) const {
      return (xCoord == pIn.xCoord) ? (yCoord < pIn.yCoord) : (xCoord < pIn.xCoord);
    }
    bool operator==(const frPoint &pIn) const {
      return (xCoord == pIn.xCoord) && (yCoord == pIn.yCoord);
    }
    bool operator!=(const frPoint &pIn) const {
      return !(*this == pIn);
    }
  protected:
    frCoord xCoord, yCoord;
  };
}

#endif
