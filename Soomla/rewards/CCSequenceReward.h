/*
 Copyright (C) 2012-2014 Soomla Inc.
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */

#include "CCReward.h"

#ifndef __CCSequenceReward_H_
#define __CCSequenceReward_H_

#include "cocos2d.h"
#include "CCSoomlaMacros.h"
#include "CCAggregateReward.h"

namespace soomla {
    class CCSequenceReward : public CCAggregateReward {
    public:
        CCSequenceReward() : CCAggregateReward() {
        };

        static CCSequenceReward *create(
                cocos2d::__String *id,
                cocos2d::__String *name,
                cocos2d::__Array *rewards
        );

        SL_CREATE_WITH_DICTIONARY(CCSequenceReward);

        virtual ~CCSequenceReward();

        virtual const char *getType() const;

        CCReward *getLastGivenReward();
        bool hasMoreToGive();
        bool forceNextRewardToGive(CCReward *reward);

    protected:
        virtual bool takeInner();

        virtual bool giveInner();
    };
}

#endif //__CCSequenceReward_H_
