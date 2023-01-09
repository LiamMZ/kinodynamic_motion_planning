#include <ompl/geometric/planners/rrt/RRTConnect.h>
#include <ompl/base/SpaceInformation.h>
#include <ompl/base/ProblemDefinition.h>

#include <kdmp/planners/include/trajectory.hpp>

namespace omplGeo = ompl::geometric;
namespace omplBase = ompl::base;

class RRTConnectTimePara
{
    RRTConnectTimePara::RRTConnectTimePara();

    Trajectory solve(std::shared_ptr<omplBase::ProblemDefinition> problem,
            std::shared_ptr<omplBase::SpaceInformation> space);

    private:
    void performTimeParameterization();
    void findStaticTrajectory();

    std::shared_ptr<omplGeo::RRTConnect> configPlanner;

    private:
    Trajectory mTrajectory;
    std::shared_ptr<omplBase::ProblemDefinition> mProblem;
    std::shared_ptr<omplBase::SpaceInformation> mSpace;
    std::vector<std::vector<double>> mConfigurations;
};