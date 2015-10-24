#pragma once

#include "Obstacle.hpp"
#include "IOnCollisionObservable.hpp"
#include "IOnCollisionObserver.hpp"
#include <vector>

namespace ButterColors {
    static constexpr GLfloat lid[3] = { 1.000f, 0.843f, 0.000f }; // Gold
    static constexpr GLfloat box[3]  = { 1.0f, 1.0f, 0.787f }; // LightYellow
}

class Butter : public Obstacle, IOnCollisionObservable
{
public:
    Butter( GLdouble x, GLdouble y, GLdouble z );
    virtual void draw() override;

    static constexpr GLfloat box_width  = cm(4);
    static constexpr GLfloat box_length = cm(6);
    static constexpr GLfloat box_height = cm(4);

    static constexpr GLfloat lid_width  = cm(5);
    static constexpr GLfloat lid_length = cm(7);
    static constexpr GLfloat lid_height = cm(1);

    virtual void processCollision(GameObject &go) override;

    // Inherited via IOnCollisionObservable
    virtual void registerOnStopCollisonObserver(IOnCollisionObserver& obj) override;
    virtual void registerOnResetCollisonObserver(IOnCollisionObserver & obj) override;

private:
    std::vector<IOnCollisionObserver*> onStopCollisionListeners;
    std::vector<IOnCollisionObserver*> onResetCollisionListeners;
};
