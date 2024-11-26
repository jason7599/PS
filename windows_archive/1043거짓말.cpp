#include <iostream>
#include <vector>

using namespace std;

int totalPeopleCount, partyCount, maxPartiesWhereICanExaggerate, versionOfTheStoryHeard[50];
vector<int> peopleComing[50];

void exaggerateOrNotAtPartyOfIndex(int partyIndex = 0, int partiesWhereIHaveLiedSoFar = 0) {
    if (partyIndex == partyCount) {
        if (partiesWhereIHaveLiedSoFar > maxPartiesWhereICanExaggerate) maxPartiesWhereICanExaggerate = partiesWhereIHaveLiedSoFar;
        return;
    }
    int versionOfTheStoryHeardCopy[50]; bool alreadyLiedToSomebodySoIShouldNotTellTheTruth = false;
    for (int personIndex : peopleComing[partyIndex]) {
        if (versionOfTheStoryHeard[personIndex] == -1) { alreadyLiedToSomebodySoIShouldNotTellTheTruth = true; break; }
        versionOfTheStoryHeardCopy[personIndex] = versionOfTheStoryHeard[personIndex];
    }
    if (!alreadyLiedToSomebodySoIShouldNotTellTheTruth) {// truth
        for (int personIndex : peopleComing[partyIndex]) versionOfTheStoryHeard[personIndex] = 1;
        exaggerateOrNotAtPartyOfIndex(partyIndex + 1, partiesWhereIHaveLiedSoFar);
        for (int personIndex : peopleComing[partyIndex]) versionOfTheStoryHeard[personIndex] = versionOfTheStoryHeardCopy[personIndex];
    }
    bool somebodyKnowsSoIShouldNotLie = false;
    for (int personIndex : peopleComing[partyIndex]) {
        if (versionOfTheStoryHeard[personIndex] == 1) { somebodyKnowsSoIShouldNotLie = true; break; }
        versionOfTheStoryHeardCopy[personIndex] = versionOfTheStoryHeard[personIndex];
    }
    if (!somebodyKnowsSoIShouldNotLie) { // lie
        for (int personIndex : peopleComing[partyIndex]) versionOfTheStoryHeard[personIndex] = -1;
        exaggerateOrNotAtPartyOfIndex(partyIndex + 1, partiesWhereIHaveLiedSoFar + 1);
        for (int personIndex : peopleComing[partyIndex]) versionOfTheStoryHeard[personIndex] = versionOfTheStoryHeardCopy[personIndex];
    }
}

int main() {
    cin >> totalPeopleCount >> partyCount;
    int howManyPeopleKnow; cin >> howManyPeopleKnow;
    while (howManyPeopleKnow--) {
        int indexOfThePersonThatKnowsTheTruth; cin >> indexOfThePersonThatKnowsTheTruth;
        versionOfTheStoryHeard[indexOfThePersonThatKnowsTheTruth - 1] = 1;
    }
    for (int i = 0; i < partyCount; i++) {
        int howManyPeopleAreComing; cin >> howManyPeopleAreComing;
        while (howManyPeopleAreComing--) {
            int thePersonThatsComing; cin >> thePersonThatsComing;
            peopleComing[i].push_back(thePersonThatsComing - 1);
        }
    }
    exaggerateOrNotAtPartyOfIndex();
    cout << maxPartiesWhereICanExaggerate;
}