/******************************************************************************
 * Copyright 2019 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 * @brief Use evaluator submodule to manage all evaluators
 */

#pragma once

#include <memory>
#include <string>

#include "cyber/component/component.h"

#include "modules/prediction/container/obstacles/obstacles_container.h"
#include "modules/prediction/submodules/container_output.h"
#include "modules/prediction/submodules/evaluator_output.h"

namespace apollo {
namespace prediction {

class EvaluatorSubmodule : public cyber::Component<ContainerOutput> {
 public:
  /**
   * @brief Destructor
   */
  ~EvaluatorSubmodule();

  /**
   * @brief Get name of the node
   * @return Name of the node
   */
  std::string Name() const;

  /**
   * @brief Initialize the node
   * @return If initialized
   */
  bool Init() override;

  /**
   * @brief Data callback upon receiving a prediction container output.
   * @param Prediction container output.
   */
  bool Proc(const std::shared_ptr<ContainerOutput>&) override;

 private:
  std::shared_ptr<cyber::Writer<EvaluatorOutput>> evaluator_writer_;
};

CYBER_REGISTER_COMPONENT(EvaluatorSubmodule)

}  // namespace prediction
}  // namespace apollo
