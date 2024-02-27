#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Address{
private:
    int zipCode;
    string streetAddress;
    string city;
    string state;
    string country;
};

enum AccountStatus{
    ACTIVE,
    DEACTIVATED,
    BLOCKED,
    DELETED
};

enum ConnectionInviteStatus{
    PENDING,
    ACCEPTED,
    IGNORED
};

enum JobStatus{
    OPEN,
    ON_HOLD,
    CLOSED
};

class Account{
private:
    string accountId;
    string password;
    string username;
    string email;
    AccountStatus status;
public:
    bool resetPassword();
};

class Person{
private:
    string name;
    Address address;
    string email;
    string phone;
    Account account;
};

class Admin : public Person{
public:
    bool blockUser(User user);
    bool unblockUser(User user);
    bool disablePage(CompanyPage page);
    bool enablePage(CompanyPage page);
    bool deleteGroup(Group group);
};

class User : public Person{
private:
    int userId;
    time_t dateOfJoining;
    Profile profile;
    vector<User> followsUsers;
    vector<CompanyPage> followCompanies;
    vector<User> connections;
    vector<Group> joinedGroups;
    vector<CompanyPage> createdPages;
    vector<Group> createdGroups;
public:
    bool sendMessage(Message message);
    bool sendInvite(ConnectionInvitation invite);
    bool cancelInvite(ConnectionInvitation invite);
    bool createPage(CompanyPage page);
    bool deletePage(CompanyPage page);
    bool createGroup(Group group);
    bool deleteGroup(Group group);
    bool createPost(Post post);
    bool deletePost(Post post);
    bool createComment(Comment comment);
    bool deleteComment(Comment comment);
    bool react(Post post);
    bool requestRecommendation(User user);
    bool acceptRecommendation(User user);
    bool applyForJob(Job job);
};

class Recommendation{
private:
    int userId;
    time_t createdOn;
    string description;
    bool isAccepted;
};

class Achievement{
private:
    string title;
    time_t dateAwarded;
    string description;
};

class Analytics{
private:
    int searchAppearances;
    int profileViews;
    int postImpressions;
    int totalConnections;
};

class Experience{
private:
    string title;
    string company;
    Address location;
    time_t startDate;
    time_t endDate;
    string description;
};

class Education{
private:
    string school;
    string degree;
    time_t startDate;
    time_t endDate;
    string description;
};

class Skill{
private:
    string name;
};

class Profile{
private:
    string headline;
    string about;
    string gender;
    vector<signed char> profilePicture;
    vector<signed char> coverPhoto;
    vector<Experience> experiences;
    vector<Education> educations;
    vector<Skill> skills;
    vector<Achievement> achievements;
    vector<Recommendation> recommendations;
    Analytics analytics;
public:
    bool addExerience(Experience experience);
    bool addEducation(Education education);
    bool addSkill(Skill skill);
    bool addAchievement(Achievement achievement);
};

class Job{
private:
    int jobId;
    string jobTitle;
    time_t dateOfPosting;
    string description;
    CompanyPage company;
    string employmentType;
    Address location;
    JobStatus status;
};

class CompanyPage{
private:
    int pageId;
    string name;
    string description;
    string type;
    int companySize;
    User createdBy;
    vector<Job> jobs;
public:
    bool createJobPosting();
    bool deleteJobPosting(Job job);
};

class Group{
private:
    int groupId;
    string name;
    string description;
    int totalMembers;
    vector<User> members;
public:
    bool updateDescription();
};

